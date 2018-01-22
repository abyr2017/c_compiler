#define program 1
#define var 2
#define begin 3
#define end 4
#define integer 5
#define char 6
#define if 7
#define then 8
#define else 9
#define while 10
#define do 11
#define read 12
#define readln 13
#define write 14
#define writeln 15
#define oprel 16
#define opadd 17
#define opmul 18

FILE *file ;
char * tamp ; /* pointeur sur chaine qui va contenir le plus long long léxéme trouver à consommer par l'analyseur syntasique */
char *commentair ; /*pointeur sur chaine qui contient le commentaire */
char*c = getc(file); /*commencer à lire le fichier un catactére à la fois */

/**char detecter_les_commentaires (char*c)
{   *c = getc(file);
    while( *c != '*')
    {
        *commentaire += *c ;
        *c = getc(file);
    }
    if ( (getc(file))==')')
        return (*commentair) ;
    else
    {

    }

}**/


while ( (*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF )
{
   *tam += *c;

    if ( (*c >= 'a')&& (*c<='z') || (*c>='A')&&(*c<='Z')) // le lexéme commence avec une lettre
    {   /**------------------------program or litteral starting with p--------------------------------------*/
        if(c=='p') // le lexéme peut être program
        {

        /*else{
            while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                *tamp=getc(file);
            return *tamp
        }*/
        }else {

         /**----------------------------var or litteral starting with v-----------------------------------------------------*/
            if(c=='v') // le lexéme peut être var
            {
             *c=getc(file);
             *tamp+=*c; //contient 2 lettres
             if(c=='a'){
                *c=getc(file); //lire la 3éme letre
                *tamp+=*c; // contient 3 lettres
                if(c=='r'){
                    *c=getc(file); //lire la 4éme lettre
                    if((*c== ' ')|| (*c == "\n") || (*c== "\t")){
                        return 2 ; ///var
                    }else{ ///litteral commence avec var
                         *tamp+=*c; //contient 4 lettres
                         while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                            *tamp=getc(file);
                        return *tamp ;/// litteral
                    }

                }else{ //*c!=r
                    while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                        *tamp=getc(file);
                    return *tamp ;/// litteral

                }
             }else{ // *c!= a
                while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                    *tamp=getc(file);
                return *tamp ;///litteral
             }

            }else{// c!= p && c!=v

         /**----------------------------begin or litteral starting with b-----------------------------------------------------*/
                if(c=='b'){
                    *c=getc(file); //lire la 2éme lettre
                    *tamp+=c; // contien 2 lettres
                    if (*c=='e'){
                        *c=getc(file); //lire la 3éme lettre
                        *tamp+=c; // contien 3 lettres
                        if(*c=='g'){
                            *c=getc(file);//lire la 4éme lettre
                            *tamp+=c;//contient 4 lettres
                            if(*c=='i'){
                                *c=getc(file);//lire la 5éme lettre
                                *tamp+=c;//contient 5lettres
                                if (*c=='n'){
                                    *c=getc(file); //lire la 6éme lettre
                                    if((*c== ' ')|| (*c == "\n") || (*c== "\t")){
                                            return 3 ; ///begin
                                    }else{ ///litteral commence avec begin
                                        *tamp+=*c; //contient 6 lettres
                                        while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                            *tamp=getc(file);
                                        return *tamp ;/// litteral commence avec begin
                                }else{//not n
                                     while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                        *tamp=getc(file);
                                    return *tamp ;///litteral
                                }
                            }else{//not i
                                 while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                    *tamp=getc(file);
                                return *tamp ;///litteral
                            }
                        }else{ //c!=g
                            while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                *tamp=getc(file);
                            return *tamp ;///litteral
                            }

                    }else{ //c!= e
                        while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                            *tamp=getc(file);
                        return *tamp ;///litteral
                    }

                }else{ //c!= p && c!= v && c!=b
                    /**----------------------------------------end or else or litteral starting with e--------------------------------------*/
                    if(*c=='e'){ //le lexéme peut être end
                            *c=getc(file); //lire la 2éme lettre
                            *tamp+=*c; //contient 2 lettres
                            if(*c=='n'){
                                *c=getc(file); //lire la 3éme lettre
                                *tamp+=*c; //contient 3 lettres
                                if(*c=='d'){
                                    *c=getc(file); //lire la 4éme lettre
                                    if((*c== ' ')|| (*c == "\n") || (*c== "\t")){
                                            return 4 ; ///end
                                    }else{ ///litteral commence avec end
                                        *tamp+=*c; //contient 4 lettres
                                        while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                            *tamp=getc(file);
                                        return *tamp ;/// litteral commence avec end

                                }else{ //not d
                                     while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                        *tamp=getc(file);
                                    return *tamp ;///litteral

                                }

                            }else{//not n
                                if(*c=='l'){ //might be else
                                    *c=getc(file); //lire la 3éme lettre
                                    *tam+=*c;//contient 3 lettres
                                    if(*c=='s'){
                                        *c=getc(file); //lire la 4éme lettre
                                        *tam+=*c;//contient 4 lettres
                                        if(*c=='e'){
                                            *c=getc(file); //lire la 5éme lettre
                                            if((*c== ' ')|| (*c == "\n") || (*c== "\t")){
                                                return 9 ; ///else
                                            }else{ ///litteral commence avec else
                                                *tamp+=*c; //contient 5 lettres
                                                while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                    *tamp=getc(file);
                                                return *tamp ;/// litteral commence avec else

                                        }else{ //not e
                                             while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                *tamp=getc(file);
                                            return *tamp ;///litteral
                                        }

                                    }else{ //not s
                                         while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                            *tamp=getc(file);
                                        return *tamp ;///litteral
                                    }


                                }else{ //not l
                                    while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                        *tamp=getc(file);
                                    return *tamp ;///litteral
                                }

                            }


                    }else{ //not in :p,v,b,e
            /**----------------------------------------char or litteral starting with c--------------------------------------*/
                            if(*c=='c'){ //le mot peut être char
                                *c=getc(file);//lire le 2éme lettre
                                *tamp+=*c;//contient 2lettres
                                if(*c=='h'){
                                    *c=getc(file);//lire le 3éme lettre
                                    *tamp+=*c;//contient 3lettres
                                    if(*c=='a'){
                                        *c=getc(file);//lire le 4éme lettre
                                        *tamp+=*c;//contient 4lettres
                                        if(*c=='r'){
                                            *c=getc(file); //lire la 5éme lettre
                                            if((*c== ' ')|| (*c == "\n") || (*c== "\t")){
                                                return 6 ; ///char
                                            }else{ ///litteral commence avec char
                                                *tamp+=*c; //contient 5 lettres
                                                while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                    *tamp=getc(file);
                                                return *tamp ;/// litteral commence avec char
                                        }else{//not r
                                            while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                *tamp=getc(file);
                                            return *tamp ;///litteral
                                        }
                                    }else{//not a
                                        while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                            *tamp=getc(file);
                                        return *tamp ;///litteral
                                    }


                                }else{ //not h
                                    while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                        *tamp=getc(file);
                                    return *tamp ;///litteral
                                }

                            }else{ //not in : p,v,b,e,c
                                if(*c=='i'){
                                        *c=getc(file);//lire le 2éme caractére
                                        *tamp+=*c;//contient 2 lettres
                                        if(*c=='f'){
                                            *c=getc(file); //lire la 3éme lettre
                                            if((*c== ' ')|| (*c == "\n") || (*c== "\t")){
                                                return 7 ; ///char
                                            }else{ ///litteral commence avec if
                                                *tamp+=*c; //contient 3 lettres
                                                while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                    *tamp+=getc(file);
                                                return *tamp ;/// litteral commence avec if

                                        }else{ // might be integer
                                            if(*c=='n'){
                                                *c=getc(file);//lire le 3éme caractére
                                                *tamp+=*c;//contient 3 lettres
                                                if(*c=='t'){
                                                    *c=getc(file);//lire le 4éme caractére
                                                    *tamp+=*c;//contient 4 lettres
                                                    if(*c=='e'){
                                                        *c=getc(file);//lire le 5éme caractére
                                                        *tamp+=*c;//contient 5 lettres
                                                        if(*c=='g'){
                                                            *c=getc(file);//lire le 6éme caractére
                                                            *tamp+=*c;//contient 6 lettres
                                                            if(*c=='e'){
                                                                *c=getc(file);//lire le 7éme caractére
                                                                *tamp+=*c;//contient 7 lettres
                                                                if(*c=='r'){
                                                                    *c=getc(file); //lire la 8éme lettre
                                                                    if((*c== ' ')|| (*c == "\n") || (*c== "\t")){
                                                                        return 5 ; ///integer
                                                                    }else{ ///litteral commence avec integer
                                                                        *tamp+=*c; //contient 8 lettres
                                                                        while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                                            *tamp+=getc(file);
                                                                        return *tamp ;/// litteral commence avec integer

                                                                }else{ // not r
                                                                    while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                                        *tamp+=getc(file);
                                                                    return *tamp ;///litteral
                                                                }
                                                            }else{ //not e
                                                                while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                                    *tamp+=getc(file);
                                                                return *tamp ;///litteral
                                                            }

                                                        }else{//not g
                                                            while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                                *tamp+=getc(file);
                                                            return *tamp ;///litteral
                                                        }
                                                    }else{//not e
                                                        while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                            *tamp+=getc(file);
                                                        return *tamp ;///litteral
                                                    }

                                                }else{//not t
                                                    while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                        *tamp+=getc(file);
                                                    return *tamp ;///litteral
                                                }

                                            }else{//not n
                                                while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                    *tamp=getc(file);
                                                return *tamp ;///litteral
                                            }
                                        }

                                }else{//not in : p,v,b,e,c,i
                                    if(*c=='d'){
                                        *c=getc(file);//lire la 2éme lettres
                                        *tamp+=*c; //contient 2 lettres
                                        if(*c=='o'){
                                            *c=getc(file); //lire la 8éme lettre
                                            if((*c== ' ')|| (*c == "\n") || (*c== "\t")){
                                                return 11 ; ///do
                                            }else{ ///litteral commence avec do
                                                *tamp+=*c; //contient 8 lettres
                                                while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                    *tamp+=getc(file);
                                                return *tamp ;/// litteral commence avec do
                                        }else{ //not o
                                            while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                *tamp=getc(file);
                                            return *tamp ;///litteral
                                        }
                                    }else{//not in :p,v,b,e,c,i,d
                                        if(*c=='t'){
                                            *c=getc(file);//lire lettre2
                                            *tamp+=*c;//contient 2 lettres
                                            if(*c=='h'){
                                                *c=getc(file);//lire lettre3
                                                *tamp+=*c; //contient 3 lettres
                                                if(*c=='e'){
                                                    *c=getc(file);//lire lettre 4
                                                    *tamp+=*c;//contient 4 lettres
                                                    if(*c=='n'){
                                                        *c=getc(file); //lire la 5éme lettre
                                                        if((*c== ' ')|| (*c == "\n") || (*c== "\t")){
                                                            return 8 ; ///then
                                                        }else{ ///litteral commence avec then
                                                            *tamp+=*c; //contient 5 lettres
                                                            while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                                *tamp+=getc(file);
                                                            return *tamp ;/// litteral commence avec then

                                                    }else{ //not n
                                                        while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                            *tamp=getc(file);
                                                        return *tamp ;///litteral
                                                    }
                                                }else{ //not e
                                                    while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                        *tamp=getc(file);
                                                    return *tamp ;///litteral
                                                }


                                            }else{//not h
                                                while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                    *tamp+=getc(file);
                                                return *tamp ;///litteral
                                            }


                                        }else{ //not in :p,v,b,e,c,i,d,t
                                            if(*c=='w'){
                                                *c=getc(file);//lire lettre 2
                                                *tamp+=*c;//contient 2 letres
                                                if(*c==h){
                                                    *c=getc(file);//lire lettre 3
                                                    *tamp+=*c;//contient 3 letres
                                                    if(*c=='i'){
                                                        *c=getc(file);//lire lettre 4
                                                        *tamp+=*c;//contient 4 letres
                                                        if(*c=='l'){
                                                            *c=getc(file);//lire lettre 5
                                                            *tamp+=*c;//contient 5 letres
                                                            if(*c=='e'){
                                                                *c=getc(file); //lire la 6éme lettre
                                                                if((*c== ' ')|| (*c == "\n") || (*c== "\t")){
                                                                    return 10 ; ///while
                                                                }else{ ///litteral commence avec while
                                                                    *tamp+=*c; //contient 6 lettres
                                                                    while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                                        *tamp+=getc(file);
                                                                    return *tamp ;/// litteral commence avec while


                                                            }else{//not e
                                                                while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                                    *tamp+=getc(file);
                                                                return *tamp ;///litteral
                                                            }

                                                        }else{//not l
                                                            while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                                *tamp+=getc(file);
                                                            return *tamp ;///litteral

                                                        }


                                                    }else{//not i
                                                        while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                            *tamp+=getc(file);
                                                        return *tamp ;///litteral
                                                    }


                                                }else{//might be write or writeln
                                                    if(*c=='r'){
                                                        *c=getc(file);//lire lettre 3
                                                        *tamp+=*c; //contient 3 lettres
                                                        if(*c==i){
                                                            *c=getc(file);//lire lettre 4
                                                            *tamp+=*c; //contient 4 lettres
                                                            if(*c==t){
                                                                *c=getc(file);//lire lettre 5
                                                                *tamp+=*c; //contient 5 lettres
                                                                if(*c=='e'){
                                                                    *c=getc(file); //lire la 6éme lettre
                                                                    if((*c== ' ')|| (*c == "\n") || (*c== "\t")){
                                                                        return 10 ; ///write
                                                                    }else{ ///litteral commence avec write
                                                                        *tamp+=*c; //contient 6 lettres
                                                                        if(*c=='l'){
                                                                            *c=getc(file);//lire lettre 7
                                                                            *tamp+=*c; //contient 7 lettres
                                                                            if(*c=='n'){
                                                                                *c=getc(file); //lire la 8éme lettre
                                                                                if((*c== ' ')|| (*c == "\n") || (*c== "\t")){
                                                                                    return 15 ; ///writeln
                                                                                }else{ ///litteral commence avec writeln
                                                                                    *tamp+=*c; //contient 8 lettres
                                                                                    while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                                                        *tamp+=getc(file);
                                                                                    return *tamp ;/// litteral commence avec writeln

                                                                            }else{//not n
                                                                                while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                                                    *tamp+=getc(file);
                                                                                return *tamp ;/// litteral commence avec writeln

                                                                            }




                                                                        }else{//not l
                                                                            *tamp+=*c; //contient 6 lettres
                                                                            while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                                                *tamp+=getc(file);
                                                                            return *tamp ;/// litteral commence avec while

                                                                        }


                                                                }else{//not e
                                                                    while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                                        *tamp+=getc(file);
                                                                    return *tamp ;///litteral
                                                                }

                                                            }else{//not t
                                                                while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                                    *tamp+=getc(file);
                                                                return *tamp ;///litteral
                                                            }

                                                        }else{//not i
                                                            while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                                *tamp+=getc(file);
                                                            return *tamp ;///litteral
                                                        }
                                                    }else{ //not r
                                                        while((*c!= ' ')&& (*c!= "\n") && (*c!= "\t") && !EOF)
                                                            *tamp+=getc(file);
                                                        return *tamp ;///litteral
                                                    }
                                                }

                                            }else{ //not in :p,v,b,e,c,i,d,t,w
                                            }
                                        }
                                    }

                                }

                            }



                    }
                }

        }
   }
} ///big while end



