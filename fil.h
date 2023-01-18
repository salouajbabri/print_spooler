
typedef struct{
    int avant;
    int arriere;
    int taille;
    int file[30];
}myfile;


void init_file(myfile f)
{
    f.avant=f.arriere=0;
}

int est_vide(myfile f)
{
    return f.avant==f.arriere;
}

int est_pleine(myfile f)
{
    return f.arriere==f.taille;
}

void emfiler(myfile *f, int x){
    f->file[f->arriere]=x;
    f->arriere++;
}

int defiler(myfile *f)
{
    return f->file[f->avant++];
}


