using namespace std;

const int 	ARRAY_SIZE = 100000,
			MIN_INTEGER = 1,
			MAX_INTEGER = 30000,
			CHOICE_SIZE = 2,
			MENU_CHOICES = 5;
			
const char	BUBBLE_SORT = 'B',
			INSERTION_SORT = 'I',
			MERGE_SORT = 'M',
			QUICK_SORT = 'Q',
			EXIT_PROGRAM = 'E';
			
const int  MENU_SPACE = 50;
const int FIRST_CHOICES = 0;
const int SEC_CHOICES = 1;
const char BUBBLE = 'B',
           INSERTS = 'I',
           MERGE = 'M';
const int DIVIDED_TWO = 2,
          INCREAMENTS = 1,
          INITIALIZED = 0;
          

//TWO FUNCTION POINTERS
extern void (*firstFuncPtr)(int*, int, int);
extern void (*secondFuncPtr)(int*, int, int);
