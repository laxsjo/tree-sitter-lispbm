/**
 * @file lispBM
 * @author Joakim Lundborg <joakim.lundborg@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "lispbm",

  rules: {
    program: ($) => repeat(choice($._expression, $.comment)),
    _expression: ($) =>
      choice(
        $.function_definition,
        $.definition,
        $.special_form,
        $.application,
        $._atom,
        $.progn,
      ),
    _atom: ($) =>
      choice(
        $.symbol,
        $.number,
        $.string,
        $.quote,
        $.unquote,
        $.unquote_splice,
        $.byte_array,
      ),
    special_form: ($) =>
      seq(
        "(",
        choice(field("special", $.special), $.function_definition),
        repeat($._expression),
        ")",
      ),
    application: ($) =>
      seq("(", field("name", $.symbol), repeat($._expression), ")"),

    progn: ($) => seq("{", repeat($._expression), "}"),
    // 1. The first character is a one of 'a' - 'z' or 'A' - 'Z' or '+-/=<>#!'.
    // 2. The rest of the characters are in 'a' - 'z' or 'A' - 'Z' or '0' - '9' or '+-/=<>!?_'.
    // 3. At most 256 characters long.
    symbol: ($) => /-?[a-zA-Z+/=<>#!][a-zA-Z0-9+\-/=<>!?_]{0,255}/,
    quote: ($) => seq("'", $._expression),
    unquote_splice: ($) => seq(",@", $._expression),
    unquote: ($) => seq(",", $._expression),
    arglist: ($) => seq("(", repeat($.symbol), ")"),
    _num_qualifier: ($) =>
      choice("b", "i", "u", "i32", "u32", "i64", "u64", "f32", "f632"),

    function_definition: ($) =>
      seq(
        "(",
        field("keyword", choice("defun", "defunret")),
        field("name", $.symbol),
        field("args", $.arglist),
        field("body", $._expression),
        ")",
      ),

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
        "quote",
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
    number: ($) => seq(/\-?\d+(\.\d+)?/, optional($._num_qualifier)),
    string: ($) => seq('"', repeat(choice(/[^"]/, '\\"')), '"'),

    byte_array: ($) => seq("[", repeat($.number), "]"),
    comment: ($) => seq(";", /.*/),
  },
});
