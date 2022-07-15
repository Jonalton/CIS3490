/**
Jonalton Jude Hamilton
1045218
jjudeham@uoguelph.ca
*/

struct set{
    char *key;
    int n;
    float prob;
};


typedef struct set set;
set* separateData(char *data,int *size);
int wordExists(set *Set, char *word,int n);
void orderKeys(set *Set,int size);
void calculateProbability(set *Set,int size);
float** optimalBST(set *Set, int size, int **R);
void findKey(char key[50],int **R,int a,int r,int size,set *Set,float **C);
void greedy(char key[50],set *Set,int start,int end);
int findHighestProb(set *Set,int start,int end);
