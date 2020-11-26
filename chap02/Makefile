ALL :=truncate select poll
all:$(ALL)
.PHONY:all


truncate:
	gcc truncate_2_9.c -o  $@

select:
	gcc select_2_10.c -o  $@
poll:
	gcc poll_2_10.c -o  $@

.PHONY:clean
clean:
	rm -f $(ALL) *.o
