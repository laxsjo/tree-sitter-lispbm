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
    _expression: ($) => choice($.specialForm, $.application, $._atom, $.progn),
    _atom: ($) => choice($.symbol, $.number, $.string, $.quote, $.byteArray),
    specialForm: ($) =>
      seq("(", field("special", $.special), repeat($._expression), ")"),
    application: ($) =>
      seq("(", field("name", $.symbol), repeat($._expression), ")"),

    progn: ($) => seq("{", repeat($._expression), "}"),
    // 1. The first character is a one of 'a' - 'z' or 'A' - 'Z' or '+-/=<>#!'.
    // 2. The rest of the characters are in 'a' - 'z' or 'A' - 'Z' or '0' - '9' or '+-/=<>!?_'.
    // 3. At most 256 characters long.
    symbol: ($) => /-?[a-zA-Z+/=<>#!][a-zA-Z0-9+\-/=<>!?_]{0,255}/,
    quote: ($) => seq("'", $._expression),
    _numQualifier: ($) =>
      choice("b", "i", "u", "i32", "u32", "i64", "u64", "f32", "f632"),
    special: ($) =>
      choice(
        "quote",
        "define",
        "lambda",
        "if",
        "progn",
        "and",
        "or",
        "let",
        "setq",
        "def",
        "defun",
        "defunret",
        "var",
      ),
    number: ($) => seq(/\-?\d+(\.\d+)?/, optional($._numQualifier)),
    string: ($) => seq('"', repeat(choice(/[^"]/, '\\"')), '"'),

    byteArray: ($) => seq("[", repeat($.number), "]"),
    comment: ($) => seq(";", /.*/),
  },
});
