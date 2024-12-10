filter:
	clang -ggdb3 -gdwarf-4 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-gnu-folding-constant -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -lm -o filter filter.c helpers.c

sepia: filter
	./filter -s ./images/courtyard.bmp ./output/output.bmp
gray: filter
	./filter -g ./images/courtyard.bmp ./output/output.bmp
reverse: filter
	./filter -r ./images/courtyard.bmp ./output/output.bmp
blur: filter
	./filter -b ./images/courtyard.bmp ./output/output.bmp