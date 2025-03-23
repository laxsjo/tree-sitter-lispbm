/**
 * @file lispBM
 * @author Joakim Lundborg <joakim.lundborg@gmail.com>
 * @author Rasmus Söderhielm <rasmus.soderhielm@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "lispbm",
  extras: ($) => [/(\s|\f)/, $.comment],
  rules: {
    program: ($) => repeat(choice($._expression, $.comment)),
    _expression: ($) =>
      choice(
        $._atom,
        $.application,
        $.definition,
        $.function,
        $.closure,
        $.function_definition,
        $.macro,
        $.macro_definition,
        $.special_form,
        $.progn,
        // Note that we define a `var` expression to be valid anywhere, not just
        // within `progn` expressions, so that invalid programs get nicer/more
        // predictable highlighting.
        $.var,
        $.let,
        $.quasiquote,
        $.quote,
        $.match,
        $.recv,
        $.recv_timeout,
      ),
    comment: ($) => token(prec(-1, /;.*/)),
    _atom: ($) => choice($.symbol, $.number, prec(1, $.invalid_number), $.string, $.byte_array),
    splice: ($) => seq(",", $._expression),
    splice_list: ($) => seq(",@", $._expression),
    special_form: ($) =>
      prec(
        -1,
        seq(
          "(",
          choice(field("special", $.special), $.function_definition),
          repeat($._expression),
          ")",
        ),
      ),
    application: ($) =>
      seq(
        "(",
        field("function", $._expression),
        field("arg", repeat($._expression)),
        ")",
      ),

    // Numbers
    
    number: ($) => choice($._int, $._float),
    _int: ($) => seq(/-?\d+/, field("qualifier", optional($._int_qualifier))),
    _int_qualifier: ($) => token.immediate(choice("b", "i", "u", "i32", "u32", "i64", "u64")),
    _float: ($) => seq(/-?\d+\.\d+/, field("qualifier", optional($._float_qualifier))),
    _float_qualifier: ($) => token.immediate(choice("f32", "f64")),
    // An integer or float literal followed by the opposite type qualifier is a
    // read error in LBM. Since we can't intentionally reject this at the parser
    // level (?) we instead create this new node that consumers can match
    // against.
    invalid_number: ($) => choice(
      seq(/-?\d+/, field("qualifier", $._float_qualifier)),
      seq(/-?\d+\.\d+/, field("qualifier", $._int_qualifier)),
    ),

    // Symbols
    // 1. The first character is a one of 'a' - 'z' or 'A' - 'Z' or '+-/=<>#!'.
    // 2. The rest of the characters are in 'a' - 'z' or 'A' - 'Z' or '0' - '9' or '+-/=<>!?_'.
    // 3. At most 256 characters long.
    // Not documented:
    // 4. If the first character is '-', the second character must not be in '0' - '9'
    symbol: ($) => choice(
      /[a-zA-Z+\/*=<>#!][a-zA-Z0-9+\-\/=<>!?_]{0,255}/,
      /-([a-zA-Z+\/=<>!?_][a-zA-Z0-9+\-\/=<>!?_]{0,254})?/,
      "_",
      "?"
    ),

    string: ($) => seq('"', repeat(choice(/[^"]/, '\\"')), '"'),
    byte_array: ($) => seq("[", repeat($.number), "]"),
    
    progn: ($) => choice(
      seq("{", repeat($._expression), "}"),
      seq("(", field("keyword", "progn"), repeat($._expression), ")"),
    ),

    // Quotes
    quote: ($) => choice(
      seq("'", $._quoted),
      seq("(", field("keyword", "quote"), $._quoted, ")")
    ),
    _quoted: ($) => choice($.quoted_list, $._atom),
    quoted_list: ($) => seq("(", repeat($._quoted), ")"),

    // Quasiquote
    quasiquote: ($) => seq("`", $._quasiquoted),
    _quasiquoted: ($) =>
      choice($.quasiquoted_list, $._atom, $.splice, $.splice_list),
    quasiquoted_list: ($) => seq("(", repeat($._quasiquoted), ")"),

    // Var
    var: ($) => seq(
      "(",
      field("keyword", "var"),
      field("name", $._destructure_pattern),
      field("value", $._expression),
      ")",
    ),
    
    // Let
    let: ($) => seq(
      "(",
      field("keyword", "let"),
      field("bindings", $.bindings),
      field("body", $._expression),
      ")",
    ),
    bindings: ($) => seq(
      "(",
      repeat($.binding),
      ")",
    ),
    binding: ($) => seq(
      "(",
      field("name", $._destructure_pattern),
      field("value", $._expression),
      ")",
    ), 
    
    _destructure_pattern: ($) => choice($.symbol, $.destructure_list),
    destructure_list: ($) => seq(
      "(",
      repeat($._destructure_pattern),
      ")",
    ),
    
    // Functions
    function: ($) =>
      seq(
        "(",
        field("keyword", choice("fn", "lambda")),
        field("args", $.arglist),
        field("body", $._expression),
        ")",
      ),
    closure: ($) =>
      seq(
        "(",
        field("keyword", "closure"),
        field("args", $.arglist),
        field("body", $._expression),
        field("environment", $._expression),
        ")",
      ),
    function_definition: ($) =>
      seq(
        "(",
        field("keyword", choice("defun", "defunret")),
        field("name", $.symbol),
        field("args", $.arglist),
        field("body", $._expression),
        ")",
      ),
    
    // Macros
    macro: ($) =>
      seq(
        "(",
        field("keyword", "macro"),
        field("args", $.arglist),
        field("body", $._expression),
        ")",
      ),
    macro_definition: ($) =>
      seq(
        "(",
        field("keyword", "defmacro"),
        field("name", $.symbol),
        field("args", $.arglist),
        field("body", $._expression),
        ")",
      ),
    
    arglist: ($) => seq("(", repeat($.symbol), ")"),

    definition: ($) =>
      seq(
        "(",
        choice("def", "define"),
        field("name", $.symbol),
        field("value", $._expression),
        ")",
      ),
    
    // Match, recv, and recv-to
    match: ($) =>
      seq(
        "(",
        field("keyword", "match"),
        field("value", $._expression),
        field("arm", repeat($.pattern_arm)),
        ")",
      ),
    recv: ($) =>
      seq(
        "(",
        field("keyword", "recv"),
        field("arm", repeat($.pattern_arm)),
        ")",
      ),
    recv_timeout: ($) =>
      seq(
        "(",
        field("keyword", "recv-to"),
        field("timeout", $.number),
        field("arm", repeat($.pattern_arm)),
        ")",
      ),
    pattern_arm: ($) =>
      seq(
        "(",
        field("pattern", $._pattern),
        optional(field("guard", $._expression)),
        field("value", $._expression),
        ")",
      ),
    _pattern: ($) =>
      choice(
        $.wildcard,
        $._atom,
        $.pattern_binding,
        $.pattern_list,
      ),
    pattern_list: ($) => seq(
      "(",
      repeat($._pattern),
      ")",
    ),
    pattern_binding: ($) =>
      prec(2, seq(
        "(",
        field("match_any", "?"),
        optional(field("type", $.symbol)),
        field("name", $.symbol),
        ")",
      )),
    wildcard: ($) => prec(1, "_"),

    special: ($) =>
      choice(
        "if",
        "and",
        "or",
        "setq",
        "import",
      ),
  },
});
