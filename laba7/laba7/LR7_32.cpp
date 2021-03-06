// LR7_32.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <process.h>
#include <malloc.h>
#include <io.h>
#include "Header.h"
int main(void)
{
	system(" chcp 1251 > nul");
	char SW;

MENU:;
	printf("\n");
	Laba(7);
	printf("\n");
	printf("1. 5.2 Запись простого файла текстовыми данными,  его чтение и распечатка\n");
	printf("2. 5.3 Создать функцию распечатки текстового файла по строкам \n");
	printf("3. 5.4 Написать фрагмент программы для записи в файл своих структур\n");
	printf("4. 5.5 Написать фрагмент программы для распечатки файла своих структур\n");
	printf("5. 5.6 Создать функцию распечатки файла своих структур\n");
	printf("6. 5.7 Написать фрагмент программы для записи файла на основе массива структур\n");
	printf("7. 5.8 Создать функцию записи в файл на основе массива своих структур\n");
	printf("8. 5.9 Написать фрагмент программы записи в массив своих структур из файла\n");
	printf("9. 5.10 Создать функцию записи из файла в массив своих структур\n");
	printf("a. 5.11 Создать функцию распечатки массива своих структур\n");
	printf("b. 5.12 Написать фрагмент программы для слияния 2-х файлов в общий файл\n");
	printf("e. Выход ...\n");
	printf("0. Меню ...\n");

	printf("Выберете пункт меню: ");
	SW = getchar();

	switch (SW)
	{
	case '1'://5.2
	{
		system("cls");
		printf("Пункт 5.2\n\n");
		const char MasFIO[][20] = { {"Костников\n"},{"Гусев\n"},{"Дюжев\n"} , {"Донченко\n"} ,  {"Акимкин\n"} };
		FILE *pF;
		pF = fopen("file.out", "w+");
		for (int i = 0; i < 5; i++)
		{
			fputs(&MasFIO[i][0], pF);
		};
		fclose(pF);
		printf("Создан файл с именем file.out\n\n");

		char buf[80];
		pF = fopen("file.out", "r+");
		printf("Вывод данных из файла с именем file.out\n\n");
		while (!feof(pF)) {
			fgets(buf, 79, pF);
			if (!feof(pF)) {
				printf("%s", buf);
			}
		}
		fclose(pF);

		SW = getchar();
		goto MENU;
		break;
	}
	case '2'://5.3
	{
		system("cls");
		printf("Пункт 5.3\n\n");
		char name[20] = "file.out";

		printf("Вывод данных из файла с именем file.out с помощью функции\n\n");

		print_file(name);

		SW = getchar();
		goto MENU;
		break;
	}
	case '3'://5.4
	{
		system("cls");
		printf("Пункт 5.4\n\n");
		book a[] = {  { "Wolf", "Jack", 2017,660,7 },{"Hart", "Jack", 2017,1100,12} ,
		{"Doffy", "Mary", 2015,1560,18} };
		FILE * p = fopen("base_struct_book_53.bin", "wb");
		printf("Создан файл с именем base_struct_book_54.bin с данными массива структур\n\n");
		for (int i = 0; i < sizeof(a) / sizeof(book); i++)
			fwrite(a + i, sizeof(book), 1, p);
		fclose(p);
		SW = getchar();
		goto MENU;
		break;
	}
	case '4'://5.5
	{
		system("cls");
		printf("Пункт 5.5\n\n");
		book temp;
		FILE * p = fopen("base_struct_book_53.bin", "rb");
		printf("Вывод данных из файла с именем base_struct_book_53.bin\n\n");
		if (p != NULL)
			while (!feof(p))
			{
				fread(&temp, sizeof(book), 1, p);
				if (!feof(p))
					print_struct_book_pointer(&temp);
			};
		fclose(p);
		SW = getchar();
		goto MENU;
		break;
	}
	case '5'://5.6
	{
		system("cls");
		printf("Пункт 5.6\n\n");
		char name[50] = "base_struct_book_53.bin";
		printf("Вывод данных из файла с именем base_struct_book_53.bin с помощью функции\n\n");
		print_struct_book_from_file(name);
		SW = getchar();
		goto MENU;
		break;
	}
	case '6'://5.7
	{
		system("cls");
		printf("Пункт 5.7\n\n");
		char name[50] = "base_struct_book_57.bin";
		book a[] = {  { "Wolf", "Jack", 2017,660,7 },{"Hart", "Jack", 2017,1100,12} ,
		{"Doffy", "Mary", 2015,1560,18} };
		FILE * p = fopen("base_struct_book_57.bin", "wb");
		for (int i = 0; i < sizeof(a) / sizeof(book); i++)
			
			fwrite(a + i, sizeof(book), 1, p);
		fclose(p);
		printf("Создан файл с именем base_struct_book_57.bin с данными массива структур\n\n");
		printf("Вывод данных из файла с именем base_struct_book_57.bin с помощью функции\n\n");
		print_struct_book_from_file(name);
		SW = getchar();
		goto MENU;
		break;
	}
	case '7'://5.8
	{
		system("cls");
		printf("Пункт 5.8\n\n");
		char name[50] = "base_struct_auto_58.bin";
		book a[] = {  { "Wolf", "Jack", 2017,660,7 },{"Hart", "Jack", 2017,1100,12} ,
		{"Doffy", "Mary", 2015,1560,18}  };
		printf("Создан файл с именем base_struct_book_58.bin с помощью функции write_struct_book\n\n");
		write_struct_book(name, a, sizeof(a) / sizeof(book));
		printf("Вывод данных из файла с именем base_struct_book_58.bin с помощью функции\n\n");
		print_struct_book_from_file(name);
		SW = getchar();
		goto MENU;
		break;
	}
	case '8'://5.9
	{
		system("cls");
		printf("Пункт 5.9\n\n");
		char name[50] = "base_struct_book_57.bin";
		FILE * pF59;

		pF59 = fopen(name, "rb");
		printf("Операция записи в массив своих структур из файла \nс именем base_struct_book_57.bin\n\n");
		int Razm = _filelength(pF59->_file) / sizeof(book); // Размер массива
		book * pWorkMas = (book *)malloc(Razm * sizeof(book));
		for (int i = 0; i < Razm; i++)
			fread(pWorkMas + i, sizeof(book), 1, pF59);
		fclose(pF59);
		printf("Распечатка массива структур\n\n");
		book_print_mas(pWorkMas, Razm);
		SW = getchar();
		goto MENU;
		break;
	}
	case '9'://5.10
	{
		system("cls");
		printf("Пункт 5.10\n\n");
		int Razm;
		book * pMas;
		printf("Операция записи в массив своих структур из файла \nс именем base_struct_book_57.bin с помощью функции\n\n");
		book_file_german("base_struct_book_57.bin", &pMas, &Razm);
		printf("Распечатка массива структур\n\n"); //
		book_print_mas(pMas, Razm);
		free(pMas);
		SW = getchar();
		goto MENU;
		break;
	}
	case 'a'://5.11
	{
		system("cls");
		printf("Пункт 5.11\n\n");
		book b[] =  {  { "Wolf", "Jack", 2017,660,7 },{"Hart", "Jack", 2017,1100,12} ,
		{"Doffy", "Mary", 2015,1560,18} };
		printf("Распечатка массива структур с помощью функции\n\n");
		book_print_mas(b, sizeof(b) / sizeof(book));
		SW = getchar();
		goto MENU;
		break;
	}
	case 'b'://5.12
	{
		system("cls");
		printf("Пункт 5.12\n\n");
		book a[] =    { "Wolf", "Jack", 2017,660,7 };
		book b[] =  {  { "Wolf", "Jack", 2017,660,7 },{"Hart", "Jack", 2017,1100,12} };
		write_struct_book("base_struct_book_n12_1.bin", a, sizeof(a) / sizeof(book));
		write_struct_book("base_struct_book_n12_2.bin", b, sizeof(b) / sizeof(book));
		book_merge_files("base_struct_book_n12.bin", "base_struct_book_n12_1.bin", "base_struct_book_n12_2.bin");
		printf("Данные из первого файла с именем base_struct_book_n12_1.bin\n\n");
		print_struct_book_from_file("base_struct_book_n12_1.bin");
		printf("Данные из второго файла с именем base_struct_book_n12_2.bin\n\n");
		print_struct_book_from_file("base_struct_book_n12_2.bin");
		printf("Данные из третьего обьедененного файла с именем base_struct_book_n12.bin\n\n");
		print_struct_book_from_file("base_struct_book_n12.bin");
		SW = getchar();
		goto MENU;
		break;
	}
	case '0':
	{
		printf("menu!\n");
		SW = getchar();
		goto MENU;
		break;
	}
	case 'e':
	{
		printf("Выбор e !\n");
		exit(0);
		break;
	}
	default:
	{
		printf("Выбор по умолчанию!!\n");
		break;
	}

	};
	system(" PAUSE");
}