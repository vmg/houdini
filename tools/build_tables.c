#include <stdio.h>

#define ALPHANUM(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
#define URL_SAFE(c) (ALPHANUM(c) || c == '-' || c == '_' || c == '.')

/* from uri/common.rb */
#define UNRESERVED(c) (ALPHANUM(c) || c == '-' || c == '_' || c == '.' || c == '!' || c == '~' || c == '*' || c == '\'' || c == '(' || c == ')')
#define RESERVED(c) (c == ';' || c == '/' || c == '?' || c == ':' || c == '@' || c== '&' || c == '=' || c == '+' || c == '$' || c == ',' || c == '[' || c == ']')
#define URI_SAFE(c) (URL_SAFE(c) || UNRESERVED(c) || RESERVED(c))

#define HREF_HTML_SAFE(c) (URL_SAFE(c) || strchr("-_.+!*(),%#@?=;:/,+$", c) != NULL)

int main(void)
{
	int i;

	printf("static const char HREF_SAFE[] = {\n\t");

	for (i = 0; i < 256; ++i) {
		printf("%d, ", HREF_HTML_SAFE(i));

		if (i % 16 == 15 && i < 255)
			printf("\n\t");
	}

	printf("};\n\n");

	printf("static const char URL_SAFE[] = {\n\t");

	for (i = 0; i < 256; ++i) {
		printf("%d, ", URL_SAFE(i));

		if (i % 16 == 15 && i < 255)
			printf("\n\t");
	}

	printf("};\n\n");

	printf("static const char URI_SAFE[] = {\n\t");

	for (i = 0; i < 256; ++i) {
		printf("%d, ", URI_SAFE(i));

		if (i % 16 == 15 && i < 255)
			printf("\n\t");
	}

	printf("};\n");

	return 0;
}
