#include "ChainList.h"
#include "ArrayList.h"
#include <ctime>
#include <locale>

int main()
{
    setlocale(LC_ALL, "Russian");


    BaseList* abstr = new ArrayList();
    BaseList* chain = new ChainList();

    BaseList* myclone_abstr = nullptr;
    BaseList* myclone_chain = nullptr;

    srand(static_cast<unsigned int>(time(0)));

    int iter = 2000;

    for (int i = 0; i < iter; i++)
    {
        int ops = rand() % 5;
        int value = rand() % 101;
        int pos = rand() % 2001;

        switch (ops)
        {
        case 0:

            abstr->Add(value);
            chain->Add(value);
            break;

        case 1:

            abstr->Delete(pos);
            chain->Delete(pos);
            break;

        case 2:

            abstr->Insert(value, pos);
            chain->Insert(value, pos);
            break;

            /*case 3:
                abstr->Clear();
                chain->Clear();
                break;*/

        case 4:

            (*abstr)[pos] = value;
            (*chain)[pos] = value;
            break;
        }
    }
    //abstr->Sort();
    //chain->Sort();

    if (abstr->IsEqual((*chain))) std::cout << "Успешно для 1 теста \n" << std::endl;
    else std::cout << "Шляпа для 1 теста" << std::endl;


    for (int i = 0; i < iter; i++)
    {
        int ops2 = rand() % 6;

        switch (ops2)
        {
        case 0:
            delete myclone_abstr;
            myclone_abstr = abstr->Clone();
            break;

        case 1:
            delete myclone_chain;
            myclone_chain = chain->Clone();
            break;

        case 2:
            abstr->Assign((*chain));
            break;

        case 3:
            chain->Assign((*abstr));
            break;

        case 4:
            chain->AssignTo((*abstr));
            break;

        case 5:
            abstr->AssignTo((*chain));
            break;
        }
    }

    if (abstr->IsEqual((*chain))) std::cout << "Успешно для 2 теста \n" << std::endl;
    else std::cout << "Шляпа для 2 теста" << std::endl;
    std::cout << "Arr count = " << abstr->Count() << "\tChain count = " << chain->Count() << std::endl << std::endl;


    abstr->Show();
    std::cout << "\n\n";
    chain->Show();

    std::cout << "Клоны: \n" << std::endl;
    myclone_abstr->Show();
    myclone_chain->Show();

   

    delete abstr;
    delete chain;
    delete myclone_abstr;
    delete myclone_chain;

    std::cout << "Констр abstr " << abstr->CrCount() << "\tДестр  " << abstr->DesCount() << std::endl << std::endl;
    std::cout << "Констр chain " << chain->CrCount() << "\tДестр  " << chain->DesCount() << std::endl << std::endl;

    std::system("pause");
}