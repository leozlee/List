single_list:
	gcc list.c list_main.c -o List -Wall
bio_list:
	gcc bio_list.c bio_list_main.c -o Bio_List -Wall
Clean:
	rm List
