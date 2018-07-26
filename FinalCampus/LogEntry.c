#include "LogEntry.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LogEntry* LogEntry_new()
{
    LogEntry* this;
    this=malloc(sizeof(LogEntry));
    return this;
}

void LogEntry_delete(LogEntry* this)
{
    free(this);
}

LogEntry* LogEntry_newConParametros(char* date,char* time,	int serviceId,	int gravedad,char* msg)
{
    LogEntry* this;
    this=LogEntry_new();

    if(
    !LogEntry_setDate(this,date)&&
    !LogEntry_setTime(this,time)&&
    !LogEntry_setServiceId(this,serviceId)&&
    !LogEntry_setGravedad(this,gravedad)&&
    !LogEntry_setMsg(this,msg))
        return this;

    LogEntry_delete(this);
    return NULL;
}

LogEntry* LogEntry_newConParametrosStr(char* date,char* time, char* serviceIdStr, char* gravedadStr,char* msg)
{
    LogEntry* this;
    this=LogEntry_new();
    int serviceId;
    int gravedad;
    serviceId = atoi(serviceIdStr);
    gravedad = atoi(gravedadStr);
    if(
    !LogEntry_setDate(this,date)&&
    !LogEntry_setTime(this,time)&&
    !LogEntry_setServiceId(this,serviceId)&&
    !LogEntry_setGravedad(this,gravedad)&&
    !LogEntry_setMsg(this,msg))
        return this;

    LogEntry_delete(this);
    return NULL;
}

int LogEntry_setDate(LogEntry* this,char* date)
{
    int retorno=-1;
    if(this!=NULL && date!=NULL)
    {
        strcpy(this->date,date);
        retorno=0;
    }
    return retorno;
}

int LogEntry_getDate(LogEntry* this,char* date)
{
    int retorno=-1;
    if(this!=NULL && date!=NULL)
    {
        strcpy(date,this->date);
        retorno=0;
    }
    return retorno;
}

int LogEntry_setTime(LogEntry* this,char* time)
{
    int retorno=-1;
    if(this!=NULL && time!=NULL)
    {
        strcpy(this->time,time);
        retorno=0;
    }
    return retorno;
}

int LogEntry_getTime(LogEntry* this,char* time)
{
    int retorno=-1;
    if(this!=NULL && time!=NULL)
    {
        strcpy(time,this->time);
        retorno=0;
    }
    return retorno;
}

int LogEntry_setServiceId(LogEntry* this,int serviceId)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->serviceId=serviceId;
        retorno=0;
    }
    return retorno;
}

int LogEntry_getServiceId(LogEntry* this,int* serviceId)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *serviceId=this->serviceId;
        retorno=0;
    }
    return retorno;
}

int LogEntry_setGravedad(LogEntry* this,int gravedad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->gravedad=gravedad;
        retorno=0;
    }
    return retorno;
}

int LogEntry_getGravedad(LogEntry* this,int* gravedad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *gravedad=this->gravedad;
        retorno=0;
    }
    return retorno;
}

int LogEntry_setMsg(LogEntry* this,char* msg)
{
    int retorno=-1;
    if(this!=NULL && msg!=NULL)
    {
        strcpy(this->msg,msg);
        retorno=0;
    }
    return retorno;
}

int LogEntry_getMsg(LogEntry* this,char* msg)
{
    int retorno=-1;
    if(this!=NULL && msg!=NULL)
    {
        strcpy(msg,this->msg);
        retorno=0;
    }
    return retorno;
}

