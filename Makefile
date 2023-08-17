build:
	mkdir -p output
	g++ src/$(file).cpp -o output/main

run:
	./output/main

clean:
	rm -rf output

dev:
	make build && make run
