#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 37
#define LARGE_STATE_COUNT 13
#define SYMBOL_COUNT 19
#define ALIAS_COUNT 0
#define TOKEN_COUNT 11
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_LPAREN = 1,
  anon_sym_RPAREN = 2,
  anon_sym_LBRACE = 3,
  anon_sym_RBRACE = 4,
  sym_symbol = 5,
  anon_sym_SQUOTE = 6,
  sym_number = 7,
  anon_sym_DQUOTE = 8,
  aux_sym_string_token1 = 9,
  anon_sym_DQUOTE_DQUOTE = 10,
  sym_program = 11,
  sym_expression = 12,
  sym_list = 13,
  sym_progn = 14,
  sym_ref = 15,
  sym_string = 16,
  aux_sym_program_repeat1 = 17,
  aux_sym_string_repeat1 = 18,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [sym_symbol] = "symbol",
  [anon_sym_SQUOTE] = "'",
  [sym_number] = "number",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [anon_sym_DQUOTE_DQUOTE] = "\"\"",
  [sym_program] = "program",
  [sym_expression] = "expression",
  [sym_list] = "list",
  [sym_progn] = "progn",
  [sym_ref] = "ref",
  [sym_string] = "string",
  [aux_sym_program_repeat1] = "program_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [sym_symbol] = sym_symbol,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [sym_number] = sym_number,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [anon_sym_DQUOTE_DQUOTE] = anon_sym_DQUOTE_DQUOTE,
  [sym_program] = sym_program,
  [sym_expression] = sym_expression,
  [sym_list] = sym_list,
  [sym_progn] = sym_progn,
  [sym_ref] = sym_ref,
  [sym_string] = sym_string,
  [aux_sym_program_repeat1] = aux_sym_program_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_symbol] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DQUOTE_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_program] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_list] = {
    .visible = true,
    .named = true,
  },
  [sym_progn] = {
    .visible = true,
    .named = true,
  },
  [sym_ref] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_program_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 6,
  [9] = 3,
  [10] = 4,
  [11] = 5,
  [12] = 2,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 13,
  [22] = 20,
  [23] = 14,
  [24] = 15,
  [25] = 16,
  [26] = 17,
  [27] = 18,
  [28] = 19,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 31,
  [33] = 30,
  [34] = 34,
  [35] = 35,
  [36] = 35,
};

static inline bool sym_symbol_character_set_1(int32_t c) {
  return (c < '/'
    ? (c < '*'
      ? (c < '&'
        ? c == '!'
        : c <= '&')
      : (c <= '+' || c == '-'))
    : (c <= '/' || (c < '_'
      ? (c < 'A'
        ? (c >= '<' && c <= '?')
        : c <= 'Z')
      : (c <= '_' || (c >= 'a' && c <= 'z')))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(3);
      if (lookahead == '"') ADVANCE(12);
      if (lookahead == '\'') ADVANCE(9);
      if (lookahead == '(') ADVANCE(4);
      if (lookahead == ')') ADVANCE(5);
      if (lookahead == '{') ADVANCE(6);
      if (lookahead == '}') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      if (lookahead == '!' ||
          ('&' <= lookahead && lookahead <= '+') ||
          lookahead == '-' ||
          lookahead == '/' ||
          ('<' <= lookahead && lookahead <= '?') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(8);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(12);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(14);
      if (lookahead != 0) ADVANCE(13);
      END_STATE();
    case 2:
      if (eof) ADVANCE(3);
      if (lookahead == '"') ADVANCE(11);
      if (lookahead == '\'') ADVANCE(9);
      if (lookahead == '(') ADVANCE(4);
      if (lookahead == ')') ADVANCE(5);
      if (lookahead == '{') ADVANCE(6);
      if (lookahead == '}') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      if (lookahead == '!' ||
          ('&' <= lookahead && lookahead <= '+') ||
          lookahead == '-' ||
          lookahead == '/' ||
          ('<' <= lookahead && lookahead <= '?') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(8);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_symbol);
      if (sym_symbol_character_set_1(lookahead)) ADVANCE(8);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      if (lookahead == '"') ADVANCE(15);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(aux_sym_string_token1);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(14);
      if (lookahead != 0 &&
          lookahead != '"') ADVANCE(13);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_DQUOTE_DQUOTE);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 2},
  [2] = {.lex_state = 2},
  [3] = {.lex_state = 2},
  [4] = {.lex_state = 2},
  [5] = {.lex_state = 2},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 2},
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 2},
  [19] = {.lex_state = 2},
  [20] = {.lex_state = 2},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 2},
  [24] = {.lex_state = 2},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 2},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 1},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [sym_symbol] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE_DQUOTE] = ACTIONS(1),
  },
  [1] = {
    [sym_program] = STATE(34),
    [sym_expression] = STATE(7),
    [sym_list] = STATE(22),
    [sym_progn] = STATE(22),
    [sym_ref] = STATE(22),
    [sym_string] = STATE(22),
    [aux_sym_program_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_LBRACE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(9),
    [anon_sym_SQUOTE] = ACTIONS(11),
    [sym_number] = ACTIONS(9),
    [anon_sym_DQUOTE] = ACTIONS(13),
  },
  [2] = {
    [sym_expression] = STATE(2),
    [sym_list] = STATE(20),
    [sym_progn] = STATE(20),
    [sym_ref] = STATE(20),
    [sym_string] = STATE(20),
    [aux_sym_program_repeat1] = STATE(2),
    [anon_sym_LPAREN] = ACTIONS(15),
    [anon_sym_RPAREN] = ACTIONS(18),
    [anon_sym_LBRACE] = ACTIONS(20),
    [anon_sym_RBRACE] = ACTIONS(18),
    [sym_symbol] = ACTIONS(23),
    [anon_sym_SQUOTE] = ACTIONS(26),
    [sym_number] = ACTIONS(23),
    [anon_sym_DQUOTE] = ACTIONS(29),
  },
  [3] = {
    [sym_expression] = STATE(2),
    [sym_list] = STATE(20),
    [sym_progn] = STATE(20),
    [sym_ref] = STATE(20),
    [sym_string] = STATE(20),
    [aux_sym_program_repeat1] = STATE(2),
    [anon_sym_LPAREN] = ACTIONS(32),
    [anon_sym_RPAREN] = ACTIONS(34),
    [anon_sym_LBRACE] = ACTIONS(36),
    [sym_symbol] = ACTIONS(38),
    [anon_sym_SQUOTE] = ACTIONS(40),
    [sym_number] = ACTIONS(38),
    [anon_sym_DQUOTE] = ACTIONS(42),
  },
  [4] = {
    [sym_expression] = STATE(2),
    [sym_list] = STATE(20),
    [sym_progn] = STATE(20),
    [sym_ref] = STATE(20),
    [sym_string] = STATE(20),
    [aux_sym_program_repeat1] = STATE(2),
    [anon_sym_LPAREN] = ACTIONS(32),
    [anon_sym_LBRACE] = ACTIONS(36),
    [anon_sym_RBRACE] = ACTIONS(44),
    [sym_symbol] = ACTIONS(38),
    [anon_sym_SQUOTE] = ACTIONS(40),
    [sym_number] = ACTIONS(38),
    [anon_sym_DQUOTE] = ACTIONS(42),
  },
  [5] = {
    [sym_expression] = STATE(4),
    [sym_list] = STATE(20),
    [sym_progn] = STATE(20),
    [sym_ref] = STATE(20),
    [sym_string] = STATE(20),
    [aux_sym_program_repeat1] = STATE(4),
    [anon_sym_LPAREN] = ACTIONS(32),
    [anon_sym_LBRACE] = ACTIONS(36),
    [anon_sym_RBRACE] = ACTIONS(46),
    [sym_symbol] = ACTIONS(38),
    [anon_sym_SQUOTE] = ACTIONS(40),
    [sym_number] = ACTIONS(38),
    [anon_sym_DQUOTE] = ACTIONS(42),
  },
  [6] = {
    [sym_expression] = STATE(3),
    [sym_list] = STATE(20),
    [sym_progn] = STATE(20),
    [sym_ref] = STATE(20),
    [sym_string] = STATE(20),
    [aux_sym_program_repeat1] = STATE(3),
    [anon_sym_LPAREN] = ACTIONS(32),
    [anon_sym_RPAREN] = ACTIONS(48),
    [anon_sym_LBRACE] = ACTIONS(36),
    [sym_symbol] = ACTIONS(38),
    [anon_sym_SQUOTE] = ACTIONS(40),
    [sym_number] = ACTIONS(38),
    [anon_sym_DQUOTE] = ACTIONS(42),
  },
  [7] = {
    [sym_expression] = STATE(12),
    [sym_list] = STATE(22),
    [sym_progn] = STATE(22),
    [sym_ref] = STATE(22),
    [sym_string] = STATE(22),
    [aux_sym_program_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(50),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_LBRACE] = ACTIONS(7),
    [sym_symbol] = ACTIONS(9),
    [anon_sym_SQUOTE] = ACTIONS(11),
    [sym_number] = ACTIONS(9),
    [anon_sym_DQUOTE] = ACTIONS(13),
  },
  [8] = {
    [sym_expression] = STATE(9),
    [sym_list] = STATE(20),
    [sym_progn] = STATE(20),
    [sym_ref] = STATE(20),
    [sym_string] = STATE(20),
    [aux_sym_program_repeat1] = STATE(9),
    [anon_sym_LPAREN] = ACTIONS(32),
    [anon_sym_RPAREN] = ACTIONS(52),
    [anon_sym_LBRACE] = ACTIONS(36),
    [sym_symbol] = ACTIONS(38),
    [anon_sym_SQUOTE] = ACTIONS(40),
    [sym_number] = ACTIONS(38),
    [anon_sym_DQUOTE] = ACTIONS(42),
  },
  [9] = {
    [sym_expression] = STATE(2),
    [sym_list] = STATE(20),
    [sym_progn] = STATE(20),
    [sym_ref] = STATE(20),
    [sym_string] = STATE(20),
    [aux_sym_program_repeat1] = STATE(2),
    [anon_sym_LPAREN] = ACTIONS(32),
    [anon_sym_RPAREN] = ACTIONS(54),
    [anon_sym_LBRACE] = ACTIONS(36),
    [sym_symbol] = ACTIONS(38),
    [anon_sym_SQUOTE] = ACTIONS(40),
    [sym_number] = ACTIONS(38),
    [anon_sym_DQUOTE] = ACTIONS(42),
  },
  [10] = {
    [sym_expression] = STATE(2),
    [sym_list] = STATE(20),
    [sym_progn] = STATE(20),
    [sym_ref] = STATE(20),
    [sym_string] = STATE(20),
    [aux_sym_program_repeat1] = STATE(2),
    [anon_sym_LPAREN] = ACTIONS(32),
    [anon_sym_LBRACE] = ACTIONS(36),
    [anon_sym_RBRACE] = ACTIONS(56),
    [sym_symbol] = ACTIONS(38),
    [anon_sym_SQUOTE] = ACTIONS(40),
    [sym_number] = ACTIONS(38),
    [anon_sym_DQUOTE] = ACTIONS(42),
  },
  [11] = {
    [sym_expression] = STATE(10),
    [sym_list] = STATE(20),
    [sym_progn] = STATE(20),
    [sym_ref] = STATE(20),
    [sym_string] = STATE(20),
    [aux_sym_program_repeat1] = STATE(10),
    [anon_sym_LPAREN] = ACTIONS(32),
    [anon_sym_LBRACE] = ACTIONS(36),
    [anon_sym_RBRACE] = ACTIONS(58),
    [sym_symbol] = ACTIONS(38),
    [anon_sym_SQUOTE] = ACTIONS(40),
    [sym_number] = ACTIONS(38),
    [anon_sym_DQUOTE] = ACTIONS(42),
  },
  [12] = {
    [sym_expression] = STATE(12),
    [sym_list] = STATE(22),
    [sym_progn] = STATE(22),
    [sym_ref] = STATE(22),
    [sym_string] = STATE(22),
    [aux_sym_program_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(18),
    [anon_sym_LPAREN] = ACTIONS(60),
    [anon_sym_LBRACE] = ACTIONS(63),
    [sym_symbol] = ACTIONS(66),
    [anon_sym_SQUOTE] = ACTIONS(69),
    [sym_number] = ACTIONS(66),
    [anon_sym_DQUOTE] = ACTIONS(72),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(75), 8,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [11] = 1,
    ACTIONS(77), 8,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [22] = 1,
    ACTIONS(79), 8,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [33] = 1,
    ACTIONS(81), 8,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [44] = 1,
    ACTIONS(83), 8,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [55] = 1,
    ACTIONS(85), 8,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [66] = 1,
    ACTIONS(87), 8,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [77] = 1,
    ACTIONS(89), 8,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [88] = 1,
    ACTIONS(75), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [98] = 1,
    ACTIONS(89), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [108] = 1,
    ACTIONS(77), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [118] = 1,
    ACTIONS(79), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [128] = 1,
    ACTIONS(81), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [138] = 1,
    ACTIONS(83), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [148] = 1,
    ACTIONS(85), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [158] = 1,
    ACTIONS(87), 7,
      ts_builtin_sym_end,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
      sym_symbol,
      anon_sym_SQUOTE,
      sym_number,
      anon_sym_DQUOTE,
  [168] = 4,
    ACTIONS(91), 1,
      anon_sym_DQUOTE,
    ACTIONS(93), 1,
      aux_sym_string_token1,
    ACTIONS(96), 1,
      anon_sym_DQUOTE_DQUOTE,
    STATE(29), 1,
      aux_sym_string_repeat1,
  [181] = 4,
    ACTIONS(99), 1,
      anon_sym_DQUOTE,
    ACTIONS(101), 1,
      aux_sym_string_token1,
    ACTIONS(103), 1,
      anon_sym_DQUOTE_DQUOTE,
    STATE(29), 1,
      aux_sym_string_repeat1,
  [194] = 4,
    ACTIONS(105), 1,
      anon_sym_DQUOTE,
    ACTIONS(107), 1,
      aux_sym_string_token1,
    ACTIONS(109), 1,
      anon_sym_DQUOTE_DQUOTE,
    STATE(33), 1,
      aux_sym_string_repeat1,
  [207] = 4,
    ACTIONS(111), 1,
      anon_sym_DQUOTE,
    ACTIONS(113), 1,
      aux_sym_string_token1,
    ACTIONS(115), 1,
      anon_sym_DQUOTE_DQUOTE,
    STATE(30), 1,
      aux_sym_string_repeat1,
  [220] = 4,
    ACTIONS(101), 1,
      aux_sym_string_token1,
    ACTIONS(103), 1,
      anon_sym_DQUOTE_DQUOTE,
    ACTIONS(117), 1,
      anon_sym_DQUOTE,
    STATE(29), 1,
      aux_sym_string_repeat1,
  [233] = 1,
    ACTIONS(119), 1,
      ts_builtin_sym_end,
  [237] = 1,
    ACTIONS(121), 1,
      sym_symbol,
  [241] = 1,
    ACTIONS(123), 1,
      sym_symbol,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(13)] = 0,
  [SMALL_STATE(14)] = 11,
  [SMALL_STATE(15)] = 22,
  [SMALL_STATE(16)] = 33,
  [SMALL_STATE(17)] = 44,
  [SMALL_STATE(18)] = 55,
  [SMALL_STATE(19)] = 66,
  [SMALL_STATE(20)] = 77,
  [SMALL_STATE(21)] = 88,
  [SMALL_STATE(22)] = 98,
  [SMALL_STATE(23)] = 108,
  [SMALL_STATE(24)] = 118,
  [SMALL_STATE(25)] = 128,
  [SMALL_STATE(26)] = 138,
  [SMALL_STATE(27)] = 148,
  [SMALL_STATE(28)] = 158,
  [SMALL_STATE(29)] = 168,
  [SMALL_STATE(30)] = 181,
  [SMALL_STATE(31)] = 194,
  [SMALL_STATE(32)] = 207,
  [SMALL_STATE(33)] = 220,
  [SMALL_STATE(34)] = 233,
  [SMALL_STATE(35)] = 237,
  [SMALL_STATE(36)] = 241,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(6),
  [18] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(5),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(20),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(35),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(31),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [34] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [36] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [38] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [40] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_program, 1),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(8),
  [63] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(11),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(22),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(36),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_program_repeat1, 2), SHIFT_REPEAT(32),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 2),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_progn, 3),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_list, 3),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ref, 2),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_progn, 2),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(29),
  [96] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(29),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [117] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [119] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_lispbm(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
