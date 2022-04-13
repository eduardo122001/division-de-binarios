#include <iostream>
#include <bitset>
using namespace std;






int main()
{   int const n=8;
    int q_valor;
    int m_valor;
    cout<<"escribe el valor del dividendo: ";
    cin>>q_valor;
    cout<<"escribe el valor del divisor: ";
    cin>>m_valor;
    bitset<n>q(q_valor);//
    bitset<n>m(m_valor);//
    bitset<n>a(0);
    int ciclo=0;
    //generamos m de forma negativa
    bitset <n>m_negativo=m.flip();
   for(int i=0;i<n;i++){

         if(m_negativo.test(i)){
            m_negativo.flip(i);

         }else{
            m_negativo.flip(i);
            break;
         }

   }
    //cout<<m_negativo<<"este es m negativo"<<endl;

    m.flip();//regresamos a m a su valor

    //cout<<"este es m "<<m<<endl;
    cout<<"EMPEZAMOS LA DIVIDION"<<endl;
    cout<<a<<" "<<q<<endl;
   for(int nb=0;nb<n;nb++){
        ciclo++;
        cout<<"ciclo "<<ciclo<<endl;
   if(q.test(7)){
   a=a<<1;
   q=q<<1;
   a.set(0);
   }else{
        a=a<<1;
        q=q<<1;
   }
   cout<<a<<" "<<q<<endl;

    cout<<m_negativo<<"             este es m negativo"<<endl;

    //HACER LA RESTA
    bool llevar=0;
    for(int i=0;i<n;i++){
        if(a.test(i)&&m_negativo.test(i)){
            if(llevar){
                a.set(i);
                llevar=1;
            }else{
                a.reset(i);
                llevar=1;
            }
        }
        else if(a.test(i)||m_negativo.test(i)){
            if(llevar){
                a.reset(i);
                llevar=1;
            }else{
                a.set(i);
                llevar=0;
            }
        }else{
            if(llevar){
                a.set(i);
                llevar=0;
            }else{
                a.reset(i);
            }
        }
    }
    cout<<a<<"             despues de la suma"<<endl;
    //SI A ES NEGATIVO O POSITIVO
    if(a.test(7)){
        q.reset(0);
    //hacemos la suma para a
        bool llevar1=0;
    for(int i=0;i<n;i++){
        if(a.test(i)&&m.test(i)){
            if(llevar1){
                a.set(i);
                llevar1=1;
            }else{
                a.reset(i);
                llevar1=1;
            }
        }
        else if(a.test(i)||m.test(i)){
            if(llevar1){
                a.reset(i);
                llevar1=1;
            }else{
                a.set(i);
                llevar1=0;
            }
        }else{
            if(llevar1){
                a.set(i);
                llevar1=0;
            }else{
                a.reset(i);
            }
        }
    }

    cout<<a<<" "<<q<<endl;
    }else{
        q.set(0);
        cout<<a<<" "<<q<<endl;
    }
   }

   cout<<q.to_ullong()<<" este es q "<<q<<endl;
   cout<<a.to_ullong()<<" este es a "<<a<<endl;
}
