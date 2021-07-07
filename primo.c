#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void form_padrao()
{
    printf("</center></h1>\n");
    printf("<form method=get action=\"/cgi-bin/primo\">");
    printf("<center><input type=number name=n min=1 max=9999999 value=\"\"><br>");
    printf("<button label=\"VERIFICAR\" name=botao>VERIFICAR</button><center>\n");
    printf("</center>\n");
    printf("</form>\n");
    printf("</body>\n");
    printf("</html>\n");
}

void primo(int num){
    int i, quantDivisores = 0;

    for(i = 1; i <= num; i++) 
    {
        if (ehDivisaoExata(num, i))
        {
            quantDivisores++;
        }
    }

    if (quantDivisores == 2) 
    {
        printf("PRIMO");
    } else {
        printf("N&Atilde;O PRIMO");
    }
    
}

int ehDivisaoExata(int dividendo, int divisor) {
    return (dividendo % divisor) == 0;
}

int main()
{
    char *param, temp[1000];
    int posicao, num, i, resultado;

    param=getenv("QUERY_STRING");
 
    printf("Content-type: text/html\n\n");
    printf("<html><head><title>VERIFICAR N&Uacute;MERO PRIMO</title></head><body>");
    
    if(strcmp(param,"")==0)
    {
        form_padrao();
    }
    else if((param[0]=='n')&&(param[1]=='='))
    {
        posicao=2;
        while((param[posicao]!='\0')&&(param[posicao]))
        {
            temp[posicao-2] = param[posicao];
            posicao++;
        }
        if(posicao>2)
        {
            num=atoi(temp);
        }
        else
        {
            num=0;
        }
	form_padrao();
        primo(num);
        printf("</body></html>");
    }
    else
    {
        form_padrao();
    }
    

    return(1);
}
