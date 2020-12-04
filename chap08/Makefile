ALL := filesize filetype
all: $(ALL)
.PHONY:all

filesize:
	gcc stat_8_1.c -o $@

filetype:
	gcc stat_filetype.c -o $@



.PHONY:clean  
clean:
	-rm -f $(ALL) *.o
