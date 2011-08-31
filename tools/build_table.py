import re

regex = re.compile('\|-\n\| (\w+)\n\|.+\n\| U\+\w+ \((\d+)\)\n\| (.+)\n')

with open('wikipedia_table.txt') as wiki_table:
    table_text = wiki_table.read()

for ent_name, dec_code, std in regex.findall(table_text):
    uni = list(unichr(int(dec_code)).encode('utf-8'))

    print '"%s", %d,' % (ent_name, len(uni)),
    print "{", ", ".join("0x%02X" % ord(c) for c in uni), "}"

