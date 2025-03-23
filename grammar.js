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
        $.function_definition,
        $.special_form,
        $.progn,
        $.quasiquote,
        $.quote,
      ),
    comment: ($) => token(prec(-1, /;.*/)),
    _atom: ($) => choice($.symbol, prec(2, $.number), $.string, $.byte_array),
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
    number: ($) => seq(/\-?\d+(\.\d+)?/, optional($._num_qualifier)),
    _num_qualifier: ($) =>
      choice("b", "i", "u", "i32", "u32", "i64", "u64", "f32", "f632"),

    // Symbols
    // 1. The first character is a one of 'a' - 'z' or 'A' - 'Z' or '+-/=<>#!'.
    // 2. The rest of the characters are in 'a' - 'z' or 'A' - 'Z' or '0' - '9' or '+-/=<>!?_'.
    // 3. At most 256 characters long.
    symbol: ($) => /[a-zA-Z+\/*\-=<>#!][a-zA-Z0-9+\-\/=<>!?_]{0,255}/,

    string: ($) => seq('"', repeat(choice(/[^"]/, '\\"')), '"'),
    byte_array: ($) => seq("[", repeat($.number), "]"),

    progn: ($) => seq("{", repeat($._expression), "}"),

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

    function_definition: ($) =>
      seq(
        "(",
        field("keyword", choice("defun", "defunret")),
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

    special: ($) =>
      choice(
        "lambda",
        "if",
        "progn",
        "and",
        "or",
        "let",
        "setq",
        "var",
        "import",
      ),
  },
});
