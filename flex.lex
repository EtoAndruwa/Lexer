%{

%}



%%

[A-Z] {printf("%s capital letter\n", yytext);
      }
.     {printf("%s not a capital letter\n", yytext);}
\n    {printf("%s not a letter\n", , yytext);}



%%


int yywrap()
{

}

int main()
{
      
      FILE* file_ptr = fopen("test.cpp", "r");
      yyin = file_ptr;

      yylex();
      
      return 0;
}
