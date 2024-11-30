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
    // TODO: add the actual grammar rules
    program: ($) => repeat($.expression),
    expression: ($) => choice($.list, $.atom),
    atom: ($) =>
      choice($.symbol, $.number, $.string, $.quote, $.byteArray, $.progn),
    list: ($) => seq("(", repeat($.expression), ")"),
    progn: ($) => seq("{", repeat($.expression), "}"),
    // 1. The first character is a one of 'a' - 'z' or 'A' - 'Z' or '+-/=<>#!'.
    // 2. The rest of the characters are in 'a' - 'z' or 'A' - 'Z' or '0' - '9' or '+-/=<>!?_'.
    // 3. At most 256 characters long.
    symbol: ($) => /[a-zA-Z+-/=<>#!][a-zA-Z0-9+-/=<>!?_]{0,255}/,
    quote: ($) => seq("'", $.symbol),
    number: ($) => /\d+/,
    string: ($) => seq('"', repeat(choice(/[^"]/, '""')), '"'),
    byteArray: ($) => seq("[", repeat($.number), "]"),
  },
});
