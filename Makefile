CFLAGS= -Wall -Werror -I src

Bin=Bin/
Obj_lib=Obj/lib/
Obj_Src=Obj/Src/
Src_lib=Src/Library/
Src_Src=Src/Src/

.PHONY: $(Bin)mySimpleComputer


$(Bin)mySimpleComputer: $(Obj_lib)main.o $(Obj_lib)mySimpleComputer.o
	g++ $(CFLAGS) -o $@ $^

$(Obj_lib)main.o: $(Src_lib)main.cpp
	g++ -c $(CFLAGS) -o $@ $<

$(Obj_lib)mySimpleComputer.o: $(Src_lib)mySimpleComputer.cpp
	g++ -c $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	rm $(Obj_lib)*.o
