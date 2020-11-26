all:
	@echo "编译第二章"
	make -C chap02
	@echo "编译第三章"
	make -C chap03
	@echo "编译第六章"
	make -C chap06


.PHONY:clean

clean:
	@echo "$(INFO)正在清理..."
	make clean -C chap02
	make clean -C chap03
	make clean -C chap06

