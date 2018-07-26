#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
typedef struct
{
    int id;
    char name[33];
    char email[65];
}Service;

Service* Service_new();
void Service_delete();
Service* Service_newConParametros(int id,char* name,char* email);

int Service_setId(Service* this,int id);
int Service_getId(Service* this,int* id);

int Service_setName(Service* this,char* name);
int Service_getName(Service* this,char* name);

int Service_setEmail(Service* this,char* email);
int Service_getEmail(Service* this,char* email);

#endif // SERVICE_H_INCLUDED
