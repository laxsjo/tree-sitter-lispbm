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
    whitespace: ($) => /[\s\t\n]/,
    expression: ($) =>
      choice($.list, $.symbol, $.progn, $.number, $.string, $.ref),
    list: ($) => seq("(", repeat($.expression), ")"),
    progn: ($) => seq("{", repeat($.expression), "}"),
    symbol: ($) => /[a-zA-Z_+*\/\-=<>!&?]+/,
    ref: ($) => seq("'", $.symbol),
    number: ($) => /\d+/,
    string: ($) => seq('"', repeat(choice(/[^"]/, '""')), '"'),
  },
});
