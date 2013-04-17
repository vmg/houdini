Houdini - The Escapist
======================

Houdini doesn't quite qualify as a library. In fact, I didn't even bother
to write a Makefile (well, others did). It's zero-dependency and modular.
Just stick the files you need in your project. Or go with all of them
(e.g. via git submodule) and use the static library that is built by
default when GNU make is invoked. Now you can freely escape some shit.

Houdini is a simple API for escaping text for the web. And unescaping it.
But that kind of breaks the joke in the name so nevermind.

- HTML escaping follows the OWASP suggestion. All other entities are left
as-is.

        & --> &amp;
        < --> &lt;
        > --> &gt;
        " --> &quot;
        ' --> &#x27;     &apos; is not recommended
        / --> &#x2F;     forward slash is included as it helps end an HTML entity

- HTML unescaping is fully RFC-compliant. Yes, that's the 253 different entities
for you, and decimal/hex code point specifiers.

- URI escaping and unescaping is fully RFC-compliant.

- URL escaping and unescaping is the same as generic URIs,
    but spaces are changed to `+`.

**WARNING:** Houdini parses **only** UTF-8 strings, and generates **only**
UTF-8 strings. If you are using another encoding, you should probably transcode
*before* passing the buffer to Houdini.

### Current API:

Do you really need docs for this?

~~~~ c
int houdini_escape_html(gh_buf *ob, const uint8_t *src, size_t size);
int houdini_escape_html0(gh_buf *ob, const uint8_t *src, size_t size, int secure);
int houdini_unescape_html(gh_buf *ob, const uint8_t *src, size_t size);
int houdini_escape_xml(gh_buf *ob, const uint8_t *src, size_t size);
int houdini_escape_uri(gh_buf *ob, const uint8_t *src, size_t size);
int houdini_escape_url(gh_buf *ob, const uint8_t *src, size_t size);
int houdini_escape_href(gh_buf *ob, const uint8_t *src, size_t size);
int houdini_unescape_uri(gh_buf *ob, const uint8_t *src, size_t size);
int houdini_unescape_url(gh_buf *ob, const uint8_t *src, size_t size);
int houdini_escape_js(gh_buf *ob, const uint8_t *src, size_t size);
int houdini_unescape_js(gh_buf *ob, const uint8_t *src, size_t size);
~~~~

Pass your string. It'll get escaped/unescaped in the target buffer, and the call will return 1.
If the given string has nothing to escape/unescape, the call will return 0 and the
output buffer will be empty.

### Questions?

Open an issue. Or shout angrily at me on Twitter ([@vmg](https://twitter.com/vmg)).
