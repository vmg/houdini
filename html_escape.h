/* C code produced by gperf version 3.0.3 */
/* Command-line: gperf -t -N find_entity -H hash_entity -K entity -C -l -E --null-strings -m100 html_escape.gperf  */
/* Computed positions: -k'1-3,5,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "html_escape.gperf"
struct html_ent {
	const char *entity;
	unsigned char utf8_len;
	unsigned char utf8[3];
};
/* maximum key range = 409, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash_entity (str, len)
     register const char *str;
     register unsigned int len;
{
  static const unsigned short asso_values[] =
    {
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419,  12,
       29,  24,   1, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419,  45, 137,  28,  17,  87,
        3,  16,   8, 103, 419,   7,  11,   1,   5,  76,
      116, 419,   1,   9,  16,  86, 419, 419,   9,   5,
        2, 419, 419, 419, 419, 419, 419,   2,  28,  26,
        4,   3, 109,  87, 141,   4, 197,   1,  36,  85,
       12,   1,   1, 189,  55,  17,   6,  34,  61,  10,
        5, 110,  11,   1, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419, 419, 419, 419,
      419, 419, 419, 419, 419, 419, 419
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[4]];
      /*FALLTHROUGH*/
      case 4:
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]+1];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

#ifdef __GNUC__
__inline
#ifdef __GNUC_STDC_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
const struct html_ent *
find_entity (str, len)
     register const char *str;
     register unsigned int len;
{
  enum
    {
      TOTAL_KEYWORDS = 252,
      MIN_WORD_LENGTH = 2,
      MAX_WORD_LENGTH = 8,
      MIN_HASH_VALUE = 10,
      MAX_HASH_VALUE = 418
    };

  static const unsigned char lengthtable[] =
    {
       0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,
       3,  0,  3,  4,  3,  3,  3,  0,  5,  6,  4,  5,  4,  4,
       3,  5,  4,  4,  5,  5,  6,  0,  5,  4,  6,  5,  5,  3,
       6,  3,  3,  5,  0,  0,  5,  5,  0,  5,  6,  6,  0,  0,
       6,  0,  0,  3,  4,  0,  3,  6,  3,  6,  5,  5,  5,  5,
       6,  6,  6,  6,  6,  2,  6,  5,  2,  6,  0,  6,  0,  3,
       4,  6,  4,  0,  0,  0,  4,  7,  3,  0,  4,  4,  6,  5,
       2,  5,  5,  5,  2,  6,  6,  3,  0,  4,  8,  2,  5,  4,
       4,  4,  6,  3,  4,  0,  0,  0,  5,  3,  6,  4,  4,  5,
       2,  6,  3,  2,  4,  3,  4,  3,  5,  4,  6,  3,  5,  5,
       5,  5,  4,  5,  5,  6,  4,  6,  5,  4,  2,  5,  5,  0,
       0,  6,  6,  4,  5,  6,  5,  6,  4,  6,  0,  4,  7,  4,
       5,  6,  4,  5,  6,  0,  0,  6,  4,  0,  4,  6,  3,  0,
       2,  6,  5,  6,  4,  4,  4,  4,  4,  4,  3,  0,  0,  5,
       6,  4,  4,  7,  0,  2,  5,  0,  2,  5,  4,  6,  2,  5,
       5,  6,  2,  4,  0,  2,  5,  0,  0,  5,  4,  6,  0,  6,
       4,  0,  3,  5,  0,  4,  0,  4,  0,  5,  6,  5,  0,  0,
       5,  5,  6,  5,  5,  6,  3,  5,  3,  0,  0,  0,  5,  3,
       0,  0,  5,  4,  0,  5,  4,  0,  5,  4,  4,  5,  7,  5,
       0,  6,  6,  6,  6,  0,  4,  4,  0,  6,  0,  0,  0,  5,
       0,  6,  6,  4,  0,  4,  0,  4,  0,  4,  3,  0,  0,  0,
       5,  7,  4,  6,  0,  6,  6,  0,  5,  0,  5,  0,  4,  0,
       4,  0,  5,  6,  0,  3,  0,  5,  0,  0,  0,  2,  0,  0,
       3,  3,  0,  5,  5,  5,  0,  0,  0,  0,  0,  5,  0,  0,
       0,  0,  0,  0,  0,  3,  6,  0,  0,  0,  0,  7,  7,  0,
       0,  0,  6,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  6,  0,  0,  0,  0,  0,  0,  0,  5,
       0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,  0,
       4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
       0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,  0,  6
    };
  static const struct html_ent wordlist[] =
    {
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0},
#line 132 "html_escape.gperf"
      {"Rho", 2, { 0xCE, 0xA1 }},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 226 "html_escape.gperf"
      {"and", 3, { 0xE2, 0x88, 0xA7 }},
      {(char*)0},
#line 161 "html_escape.gperf"
      {"phi", 2, { 0xCF, 0x86 }},
#line 148 "html_escape.gperf"
      {"iota", 2, { 0xCE, 0xB9 }},
#line 163 "html_escape.gperf"
      {"psi", 2, { 0xCF, 0x88 }},
#line 8 "html_escape.gperf"
      {"amp", 1, { 0x26 }},
#line 230 "html_escape.gperf"
      {"int", 3, { 0xE2, 0x88, 0xAB }},
      {(char*)0},
#line 147 "html_escape.gperf"
      {"theta", 2, { 0xCE, 0xB8 }},
#line 231 "html_escape.gperf"
      {"there4", 3, { 0xE2, 0x88, 0xB4 }},
#line 223 "html_escape.gperf"
      {"prop", 3, { 0xE2, 0x88, 0x9D }},
#line 164 "html_escape.gperf"
      {"omega", 2, { 0xCF, 0x89 }},
#line 167 "html_escape.gperf"
      {"ensp", 3, { 0xE2, 0x80, 0x82 }},
#line 218 "html_escape.gperf"
      {"prod", 3, { 0xE2, 0x88, 0x8F }},
#line 24 "html_escape.gperf"
      {"not", 2, { 0xC2, 0xAC }},
#line 194 "html_escape.gperf"
      {"image", 3, { 0xE2, 0x84, 0x91 }},
#line 215 "html_escape.gperf"
      {"isin", 3, { 0xE2, 0x88, 0x88 }},
#line 247 "html_escape.gperf"
      {"sdot", 3, { 0xE2, 0x8B, 0x85 }},
#line 123 "html_escape.gperf"
      {"Theta", 2, { 0xCE, 0x98 }},
#line 187 "html_escape.gperf"
      {"prime", 3, { 0xE2, 0x80, 0xB2 }},
#line 110 "html_escape.gperf"
      {"Scaron", 2, { 0xC5, 0xA0 }},
      {(char*)0},
#line 197 "html_escape.gperf"
      {"trade", 3, { 0xE2, 0x84, 0xA2 }},
#line 168 "html_escape.gperf"
      {"emsp", 3, { 0xE2, 0x80, 0x83 }},
#line 169 "html_escape.gperf"
      {"thinsp", 3, { 0xE2, 0x80, 0x89 }},
#line 149 "html_escape.gperf"
      {"kappa", 2, { 0xCE, 0xBA }},
#line 106 "html_escape.gperf"
      {"thorn", 2, { 0xC3, 0xBE }},
#line 162 "html_escape.gperf"
      {"chi", 2, { 0xCF, 0x87 }},
#line 111 "html_escape.gperf"
      {"scaron", 2, { 0xC5, 0xA1 }},
#line 137 "html_escape.gperf"
      {"Chi", 2, { 0xCE, 0xA7 }},
#line 146 "html_escape.gperf"
      {"eta", 2, { 0xCE, 0xB7 }},
#line 125 "html_escape.gperf"
      {"Kappa", 2, { 0xCE, 0x9A }},
      {(char*)0}, {(char*)0},
#line 216 "html_escape.gperf"
      {"notin", 3, { 0xE2, 0x88, 0x89 }},
#line 15 "html_escape.gperf"
      {"pound", 2, { 0xC2, 0xA3 }},
      {(char*)0},
#line 32 "html_escape.gperf"
      {"acute", 2, { 0xC2, 0xB4 }},
#line 97 "html_escape.gperf"
      {"otilde", 2, { 0xC3, 0xB5 }},
#line 79 "html_escape.gperf"
      {"atilde", 2, { 0xC3, 0xA3 }},
      {(char*)0}, {(char*)0},
#line 61 "html_escape.gperf"
      {"Ntilde", 2, { 0xC3, 0x91 }},
      {(char*)0}, {(char*)0},
#line 228 "html_escape.gperf"
      {"cap", 3, { 0xE2, 0x88, 0xA9 }},
#line 12 "html_escape.gperf"
      {"nbsp", 2, { 0xC2, 0xA0 }},
      {(char*)0},
#line 254 "html_escape.gperf"
      {"loz", 3, { 0xE2, 0x97, 0x8A }},
#line 93 "html_escape.gperf"
      {"ntilde", 2, { 0xC3, 0xB1 }},
#line 156 "html_escape.gperf"
      {"rho", 2, { 0xCF, 0x81 }},
#line 245 "html_escape.gperf"
      {"otimes", 3, { 0xE2, 0x8A, 0x97 }},
#line 96 "html_escape.gperf"
      {"ocirc", 2, { 0xC3, 0xB4 }},
#line 78 "html_escape.gperf"
      {"acirc", 2, { 0xC3, 0xA2 }},
#line 86 "html_escape.gperf"
      {"ecirc", 2, { 0xC3, 0xAA }},
#line 90 "html_escape.gperf"
      {"icirc", 2, { 0xC3, 0xAE }},
#line 95 "html_escape.gperf"
      {"oacute", 2, { 0xC3, 0xB3 }},
#line 77 "html_escape.gperf"
      {"aacute", 2, { 0xC3, 0xA1 }},
#line 85 "html_escape.gperf"
      {"eacute", 2, { 0xC3, 0xA9 }},
#line 89 "html_escape.gperf"
      {"iacute", 2, { 0xC3, 0xAD }},
#line 73 "html_escape.gperf"
      {"Yacute", 2, { 0xC3, 0x9D }},
#line 227 "html_escape.gperf"
      {"or", 3, { 0xE2, 0x88, 0xA8 }},
#line 221 "html_escape.gperf"
      {"lowast", 3, { 0xE2, 0x88, 0x97 }},
#line 214 "html_escape.gperf"
      {"nabla", 3, { 0xE2, 0x88, 0x87 }},
#line 10 "html_escape.gperf"
      {"lt", 1, { 0x3C }},
#line 83 "html_escape.gperf"
      {"ccedil", 2, { 0xC3, 0xA7 }},
      {(char*)0},
#line 51 "html_escape.gperf"
      {"Ccedil", 2, { 0xC3, 0x87 }},
      {(char*)0},
#line 240 "html_escape.gperf"
      {"sup", 3, { 0xE2, 0x8A, 0x83 }},
#line 241 "html_escape.gperf"
      {"nsub", 3, { 0xE2, 0x8A, 0x84 }},
#line 189 "html_escape.gperf"
      {"lsaquo", 3, { 0xE2, 0x80, 0xB9 }},
#line 243 "html_escape.gperf"
      {"supe", 3, { 0xE2, 0x8A, 0x87 }},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 34 "html_escape.gperf"
      {"para", 2, { 0xC2, 0xB6 }},
#line 154 "html_escape.gperf"
      {"omicron", 2, { 0xCE, 0xBF }},
#line 229 "html_escape.gperf"
      {"cup", 3, { 0xE2, 0x88, 0xAA }},
      {(char*)0},
#line 211 "html_escape.gperf"
      {"part", 3, { 0xE2, 0x88, 0x82 }},
#line 37 "html_escape.gperf"
      {"sup1", 2, { 0xC2, 0xB9 }},
#line 47 "html_escape.gperf"
      {"Atilde", 2, { 0xC3, 0x83 }},
#line 140 "html_escape.gperf"
      {"alpha", 2, { 0xCE, 0xB1 }},
#line 127 "html_escape.gperf"
      {"Mu", 2, { 0xCE, 0x9C }},
#line 103 "html_escape.gperf"
      {"ucirc", 2, { 0xC3, 0xBB }},
#line 139 "html_escape.gperf"
      {"Omega", 2, { 0xCE, 0xA9 }},
#line 191 "html_escape.gperf"
      {"oline", 3, { 0xE2, 0x80, 0xBE }},
#line 128 "html_escape.gperf"
      {"Nu", 2, { 0xCE, 0x9D }},
#line 102 "html_escape.gperf"
      {"uacute", 2, { 0xC3, 0xBA }},
#line 190 "html_escape.gperf"
      {"rsaquo", 3, { 0xE2, 0x80, 0xBA }},
#line 159 "html_escape.gperf"
      {"tau", 2, { 0xCF, 0x84 }},
      {(char*)0},
#line 31 "html_escape.gperf"
      {"sup3", 2, { 0xC2, 0xB3 }},
#line 165 "html_escape.gperf"
      {"thetasym", 2, { 0xCF, 0x91 }},
#line 152 "html_escape.gperf"
      {"nu", 2, { 0xCE, 0xBD }},
#line 46 "html_escape.gperf"
      {"Acirc", 2, { 0xC3, 0x82 }},
#line 38 "html_escape.gperf"
      {"ordm", 2, { 0xC2, 0xBA }},
#line 30 "html_escape.gperf"
      {"sup2", 2, { 0xC2, 0xB2 }},
#line 242 "html_escape.gperf"
      {"sube", 3, { 0xE2, 0x8A, 0x86 }},
#line 45 "html_escape.gperf"
      {"Aacute", 2, { 0xC3, 0x81 }},
#line 134 "html_escape.gperf"
      {"Tau", 2, { 0xCE, 0xA4 }},
#line 124 "html_escape.gperf"
      {"Iota", 2, { 0xCE, 0x99 }},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 248 "html_escape.gperf"
      {"lceil", 3, { 0xE2, 0x8C, 0x88 }},
#line 20 "html_escape.gperf"
      {"uml", 2, { 0xC2, 0xA8 }},
#line 43 "html_escape.gperf"
      {"iquest", 2, { 0xC2, 0xBF }},
#line 121 "html_escape.gperf"
      {"Zeta", 2, { 0xCE, 0x96 }},
#line 193 "html_escape.gperf"
      {"euro", 3, { 0xE2, 0x82, 0xAC }},
#line 234 "html_escape.gperf"
      {"asymp", 3, { 0xE2, 0x89, 0x88 }},
#line 235 "html_escape.gperf"
      {"ne", 3, { 0xE2, 0x89, 0xA0 }},
#line 65 "html_escape.gperf"
      {"Otilde", 2, { 0xC3, 0x95 }},
#line 122 "html_escape.gperf"
      {"Eta", 2, { 0xCE, 0x97 }},
#line 11 "html_escape.gperf"
      {"gt", 1, { 0x3E }},
#line 233 "html_escape.gperf"
      {"cong", 3, { 0xE2, 0x89, 0x85 }},
#line 136 "html_escape.gperf"
      {"Phi", 2, { 0xCE, 0xA6 }},
#line 145 "html_escape.gperf"
      {"zeta", 2, { 0xCE, 0xB6 }},
#line 138 "html_escape.gperf"
      {"Psi", 2, { 0xCE, 0xA8 }},
#line 212 "html_escape.gperf"
      {"exist", 3, { 0xE2, 0x88, 0x83 }},
#line 22 "html_escape.gperf"
      {"ordf", 2, { 0xC2, 0xAA }},
#line 126 "html_escape.gperf"
      {"Lambda", 2, { 0xCE, 0x9B }},
#line 239 "html_escape.gperf"
      {"sub", 3, { 0xE2, 0x8A, 0x82 }},
#line 118 "html_escape.gperf"
      {"Gamma", 2, { 0xCE, 0x93 }},
#line 249 "html_escape.gperf"
      {"rceil", 3, { 0xE2, 0x8C, 0x89 }},
#line 116 "html_escape.gperf"
      {"Alpha", 2, { 0xCE, 0x91 }},
#line 64 "html_escape.gperf"
      {"Ocirc", 2, { 0xC3, 0x94 }},
#line 21 "html_escape.gperf"
      {"copy", 2, { 0xC2, 0xA9 }},
#line 224 "html_escape.gperf"
      {"infin", 3, { 0xE2, 0x88, 0x9E }},
#line 222 "html_escape.gperf"
      {"radic", 3, { 0xE2, 0x88, 0x9A }},
#line 63 "html_escape.gperf"
      {"Oacute", 2, { 0xC3, 0x93 }},
#line 202 "html_escape.gperf"
      {"darr", 3, { 0xE2, 0x86, 0x93 }},
#line 40 "html_escape.gperf"
      {"frac14", 2, { 0xC2, 0xBC }},
#line 188 "html_escape.gperf"
      {"Prime", 3, { 0xE2, 0x80, 0xB3 }},
#line 141 "html_escape.gperf"
      {"beta", 2, { 0xCE, 0xB2 }},
#line 237 "html_escape.gperf"
      {"le", 3, { 0xE2, 0x89, 0xA4 }},
#line 71 "html_escape.gperf"
      {"Ucirc", 2, { 0xC3, 0x9B }},
#line 54 "html_escape.gperf"
      {"Ecirc", 2, { 0xC3, 0x8A }},
      {(char*)0}, {(char*)0},
#line 70 "html_escape.gperf"
      {"Uacute", 2, { 0xC3, 0x9A }},
#line 53 "html_escape.gperf"
      {"Eacute", 2, { 0xC3, 0x89 }},
#line 14 "html_escape.gperf"
      {"cent", 2, { 0xC2, 0xA2 }},
#line 143 "html_escape.gperf"
      {"delta", 2, { 0xCE, 0xB4 }},
#line 42 "html_escape.gperf"
      {"frac34", 2, { 0xC2, 0xBE }},
#line 204 "html_escape.gperf"
      {"crarr", 3, { 0xE2, 0x86, 0xB5 }},
#line 150 "html_escape.gperf"
      {"lambda", 2, { 0xCE, 0xBB }},
#line 19 "html_escape.gperf"
      {"sect", 2, { 0xC2, 0xA7 }},
#line 16 "html_escape.gperf"
      {"curren", 2, { 0xC2, 0xA4 }},
      {(char*)0},
#line 184 "html_escape.gperf"
      {"bull", 3, { 0xE2, 0x80, 0xA2 }},
#line 130 "html_escape.gperf"
      {"Omicron", 2, { 0xCE, 0x9F }},
#line 252 "html_escape.gperf"
      {"lang", 3, { 0xE2, 0x9F, 0xA8 }},
#line 58 "html_escape.gperf"
      {"Icirc", 2, { 0xC3, 0x8E }},
#line 18 "html_escape.gperf"
      {"brvbar", 2, { 0xC2, 0xA6 }},
#line 246 "html_escape.gperf"
      {"perp", 3, { 0xE2, 0x8A, 0xA5 }},
#line 119 "html_escape.gperf"
      {"Delta", 2, { 0xCE, 0x94 }},
#line 57 "html_escape.gperf"
      {"Iacute", 2, { 0xC3, 0x8D }},
      {(char*)0}, {(char*)0},
#line 41 "html_escape.gperf"
      {"frac12", 2, { 0xC2, 0xBD }},
#line 200 "html_escape.gperf"
      {"uarr", 3, { 0xE2, 0x86, 0x91 }},
      {(char*)0},
#line 199 "html_escape.gperf"
      {"larr", 3, { 0xE2, 0x86, 0x90 }},
#line 105 "html_escape.gperf"
      {"yacute", 2, { 0xC3, 0xBD }},
#line 225 "html_escape.gperf"
      {"ang", 3, { 0xE2, 0x88, 0xA0 }},
      {(char*)0},
#line 151 "html_escape.gperf"
      {"mu", 2, { 0xCE, 0xBC }},
#line 182 "html_escape.gperf"
      {"dagger", 3, { 0xE2, 0x80, 0xA0 }},
#line 256 "html_escape.gperf"
      {"clubs", 3, { 0xE2, 0x99, 0xA3 }},
#line 195 "html_escape.gperf"
      {"weierp", 3, { 0xE2, 0x84, 0x98 }},
#line 253 "html_escape.gperf"
      {"rang", 3, { 0xE2, 0x9F, 0xA9 }},
#line 98 "html_escape.gperf"
      {"ouml", 2, { 0xC3, 0xB6 }},
#line 80 "html_escape.gperf"
      {"auml", 2, { 0xC3, 0xA4 }},
#line 87 "html_escape.gperf"
      {"euml", 2, { 0xC3, 0xAB }},
#line 91 "html_escape.gperf"
      {"iuml", 2, { 0xC3, 0xAF }},
#line 112 "html_escape.gperf"
      {"Yuml", 2, { 0xC5, 0xB8 }},
#line 60 "html_escape.gperf"
      {"ETH", 2, { 0xC3, 0x90 }},
      {(char*)0}, {(char*)0},
#line 13 "html_escape.gperf"
      {"iexcl", 2, { 0xC2, 0xA1 }},
#line 183 "html_escape.gperf"
      {"Dagger", 3, { 0xE2, 0x80, 0xA1 }},
#line 201 "html_escape.gperf"
      {"rarr", 3, { 0xE2, 0x86, 0x92 }},
#line 27 "html_escape.gperf"
      {"macr", 2, { 0xC2, 0xAF }},
#line 198 "html_escape.gperf"
      {"alefsym", 3, { 0xE2, 0x84, 0xB5 }},
      {(char*)0},
#line 238 "html_escape.gperf"
      {"ge", 3, { 0xE2, 0x89, 0xA5 }},
#line 81 "html_escape.gperf"
      {"aring", 2, { 0xC3, 0xA5 }},
      {(char*)0},
#line 155 "html_escape.gperf"
      {"pi", 2, { 0xCF, 0x80 }},
#line 192 "html_escape.gperf"
      {"frasl", 3, { 0xE2, 0x81, 0x84 }},
#line 196 "html_escape.gperf"
      {"real", 3, { 0xE2, 0x84, 0x9C }},
#line 100 "html_escape.gperf"
      {"oslash", 2, { 0xC3, 0xB8 }},
#line 153 "html_escape.gperf"
      {"xi", 2, { 0xCE, 0xBE }},
#line 142 "html_escape.gperf"
      {"gamma", 2, { 0xCE, 0xB3 }},
#line 74 "html_escape.gperf"
      {"THORN", 2, { 0xC3, 0x9E }},
#line 186 "html_escape.gperf"
      {"permil", 3, { 0xE2, 0x80, 0xB0 }},
#line 129 "html_escape.gperf"
      {"Xi", 2, { 0xCE, 0x9E }},
#line 9 "html_escape.gperf"
      {"apos", 1, { 0x27 }},
      {(char*)0},
#line 217 "html_escape.gperf"
      {"ni", 3, { 0xE2, 0x88, 0x8B }},
#line 36 "html_escape.gperf"
      {"cedil", 2, { 0xC2, 0xB8 }},
      {(char*)0}, {(char*)0},
#line 236 "html_escape.gperf"
      {"equiv", 3, { 0xE2, 0x89, 0xA1 }},
#line 104 "html_escape.gperf"
      {"uuml", 2, { 0xC3, 0xBC }},
#line 250 "html_escape.gperf"
      {"lfloor", 3, { 0xE2, 0x8C, 0x8A }},
      {(char*)0},
#line 29 "html_escape.gperf"
      {"plusmn", 2, { 0xC2, 0xB1 }},
#line 113 "html_escape.gperf"
      {"fnof", 2, { 0xC6, 0x92 }},
      {(char*)0},
#line 172 "html_escape.gperf"
      {"lrm", 3, { 0xE2, 0x80, 0x8E }},
#line 181 "html_escape.gperf"
      {"bdquo", 3, { 0xE2, 0x80, 0x9E }},
      {(char*)0},
#line 170 "html_escape.gperf"
      {"zwnj", 3, { 0xE2, 0x80, 0x8C }},
      {(char*)0},
#line 48 "html_escape.gperf"
      {"Auml", 2, { 0xC3, 0x84 }},
      {(char*)0},
#line 75 "html_escape.gperf"
      {"szlig", 2, { 0xC3, 0x9F }},
#line 255 "html_escape.gperf"
      {"spades", 3, { 0xE2, 0x99, 0xA0 }},
#line 179 "html_escape.gperf"
      {"ldquo", 3, { 0xE2, 0x80, 0x9C }},
      {(char*)0}, {(char*)0},
#line 176 "html_escape.gperf"
      {"lsquo", 3, { 0xE2, 0x80, 0x98 }},
#line 178 "html_escape.gperf"
      {"sbquo", 3, { 0xE2, 0x80, 0x9A }},
#line 251 "html_escape.gperf"
      {"rfloor", 3, { 0xE2, 0x8C, 0x8B }},
#line 213 "html_escape.gperf"
      {"empty", 3, { 0xE2, 0x88, 0x85 }},
#line 258 "html_escape.gperf"
      {"diams", 3, { 0xE2, 0x99, 0xA6 }},
#line 210 "html_escape.gperf"
      {"forall", 3, { 0xE2, 0x88, 0x80 }},
#line 25 "html_escape.gperf"
      {"shy", 2, { 0xC2, 0xAD }},
#line 49 "html_escape.gperf"
      {"Aring", 2, { 0xC3, 0x85 }},
#line 17 "html_escape.gperf"
      {"yen", 2, { 0xC2, 0xA5 }},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 115 "html_escape.gperf"
      {"tilde", 2, { 0xCB, 0x9C }},
#line 219 "html_escape.gperf"
      {"sum", 3, { 0xE2, 0x88, 0x91 }},
      {(char*)0}, {(char*)0},
#line 180 "html_escape.gperf"
      {"rdquo", 3, { 0xE2, 0x80, 0x9D }},
#line 208 "html_escape.gperf"
      {"dArr", 3, { 0xE2, 0x87, 0x93 }},
      {(char*)0},
#line 177 "html_escape.gperf"
      {"rsquo", 3, { 0xE2, 0x80, 0x99 }},
#line 117 "html_escape.gperf"
      {"Beta", 2, { 0xCE, 0x92 }},
      {(char*)0},
#line 23 "html_escape.gperf"
      {"laquo", 2, { 0xC2, 0xAB }},
#line 7 "html_escape.gperf"
      {"quot", 1, { 0x22 }},
#line 66 "html_escape.gperf"
      {"Ouml", 2, { 0xC3, 0x96 }},
#line 50 "html_escape.gperf"
      {"AElig", 2, { 0xC3, 0x86 }},
#line 144 "html_escape.gperf"
      {"epsilon", 2, { 0xCE, 0xB5 }},
#line 244 "html_escape.gperf"
      {"oplus", 3, { 0xE2, 0x8A, 0x95 }},
      {(char*)0},
#line 94 "html_escape.gperf"
      {"ograve", 2, { 0xC3, 0xB2 }},
#line 76 "html_escape.gperf"
      {"agrave", 2, { 0xC3, 0xA0 }},
#line 84 "html_escape.gperf"
      {"egrave", 2, { 0xC3, 0xA8 }},
#line 88 "html_escape.gperf"
      {"igrave", 2, { 0xC3, 0xAC }},
      {(char*)0},
#line 72 "html_escape.gperf"
      {"Uuml", 2, { 0xC3, 0x9C }},
#line 55 "html_escape.gperf"
      {"Euml", 2, { 0xC3, 0x8B }},
      {(char*)0},
#line 99 "html_escape.gperf"
      {"divide", 2, { 0xC3, 0xB7 }},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 39 "html_escape.gperf"
      {"raquo", 2, { 0xC2, 0xBB }},
      {(char*)0},
#line 257 "html_escape.gperf"
      {"hearts", 3, { 0xE2, 0x99, 0xA5 }},
#line 68 "html_escape.gperf"
      {"Oslash", 2, { 0xC3, 0x98 }},
#line 203 "html_escape.gperf"
      {"harr", 3, { 0xE2, 0x86, 0x94 }},
      {(char*)0},
#line 206 "html_escape.gperf"
      {"uArr", 3, { 0xE2, 0x87, 0x91 }},
      {(char*)0},
#line 205 "html_escape.gperf"
      {"lArr", 3, { 0xE2, 0x87, 0x90 }},
      {(char*)0},
#line 59 "html_escape.gperf"
      {"Iuml", 2, { 0xC3, 0x8F }},
#line 28 "html_escape.gperf"
      {"deg", 2, { 0xC2, 0xB0 }},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 108 "html_escape.gperf"
      {"OElig", 2, { 0xC5, 0x92 }},
#line 160 "html_escape.gperf"
      {"upsilon", 2, { 0xCF, 0x85 }},
#line 107 "html_escape.gperf"
      {"yuml", 2, { 0xC3, 0xBF }},
#line 185 "html_escape.gperf"
      {"hellip", 3, { 0xE2, 0x80, 0xA6 }},
      {(char*)0},
#line 35 "html_escape.gperf"
      {"middot", 2, { 0xC2, 0xB7 }},
#line 101 "html_escape.gperf"
      {"ugrave", 2, { 0xC3, 0xB9 }},
      {(char*)0},
#line 133 "html_escape.gperf"
      {"Sigma", 2, { 0xCE, 0xA3 }},
      {(char*)0},
#line 174 "html_escape.gperf"
      {"ndash", 3, { 0xE2, 0x80, 0x93 }},
      {(char*)0},
#line 207 "html_escape.gperf"
      {"rArr", 3, { 0xE2, 0x87, 0x92 }},
      {(char*)0},
#line 114 "html_escape.gperf"
      {"circ", 2, { 0xCB, 0x86 }},
      {(char*)0},
#line 158 "html_escape.gperf"
      {"sigma", 2, { 0xCF, 0x83 }},
#line 44 "html_escape.gperf"
      {"Agrave", 2, { 0xC3, 0x80 }},
      {(char*)0},
#line 173 "html_escape.gperf"
      {"rlm", 3, { 0xE2, 0x80, 0x8F }},
      {(char*)0},
#line 33 "html_escape.gperf"
      {"micro", 2, { 0xC2, 0xB5 }},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 131 "html_escape.gperf"
      {"Pi", 2, { 0xCE, 0xA0 }},
      {(char*)0}, {(char*)0},
#line 92 "html_escape.gperf"
      {"eth", 2, { 0xC3, 0xB0 }},
#line 166 "html_escape.gperf"
      {"piv", 2, { 0xCF, 0x96 }},
      {(char*)0},
#line 109 "html_escape.gperf"
      {"oelig", 2, { 0xC5, 0x93 }},
#line 82 "html_escape.gperf"
      {"aelig", 2, { 0xC3, 0xA6 }},
#line 67 "html_escape.gperf"
      {"times", 2, { 0xC3, 0x97 }},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 220 "html_escape.gperf"
      {"minus", 3, { 0xE2, 0x88, 0x92 }},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 26 "html_escape.gperf"
      {"reg", 2, { 0xC2, 0xAE }},
#line 62 "html_escape.gperf"
      {"Ograve", 2, { 0xC3, 0x92 }},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 135 "html_escape.gperf"
      {"Upsilon", 2, { 0xCE, 0xA5 }},
#line 120 "html_escape.gperf"
      {"Epsilon", 2, { 0xCE, 0x95 }},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 69 "html_escape.gperf"
      {"Ugrave", 2, { 0xC3, 0x99 }},
#line 52 "html_escape.gperf"
      {"Egrave", 2, { 0xC3, 0x88 }},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 56 "html_escape.gperf"
      {"Igrave", 2, { 0xC3, 0x8C }},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0},
#line 175 "html_escape.gperf"
      {"mdash", 3, { 0xE2, 0x80, 0x94 }},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0},
#line 232 "html_escape.gperf"
      {"sim", 3, { 0xE2, 0x88, 0xBC }},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 209 "html_escape.gperf"
      {"hArr", 3, { 0xE2, 0x87, 0x94 }},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 171 "html_escape.gperf"
      {"zwj", 3, { 0xE2, 0x80, 0x8D }},
      {(char*)0}, {(char*)0}, {(char*)0}, {(char*)0},
#line 157 "html_escape.gperf"
      {"sigmaf", 2, { 0xCF, 0x82 }}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash_entity (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        if (len == lengthtable[key])
          {
            register const char *s = wordlist[key].entity;

            if (s && *str == *s && !memcmp (str + 1, s + 1, len - 1))
              return &wordlist[key];
          }
    }
  return 0;
}
