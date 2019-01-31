main:
	gcc ./src/*c -o main
.PHONY: clean
clean:
	rm -f main