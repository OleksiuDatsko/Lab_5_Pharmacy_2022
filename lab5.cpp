#include <iostream>
using namespace std;

#define DATE 202211 //YYYYMM

class Medecine
{
public:
    string name_ = "";
    int price_ = 0;
    int quantity_ = 0;
    bool is_prescription_needed_ = 0;
    int expiration_date_ = 0; //YYYYMM

    void AddNewMedecine();
    void OutputMedecine();
};
class Pharmacy
{
    private:
        int size_ = 0;
        Medecine* medecine_ = new Medecine[size_]; //асортимент ліків
    public:
        void AddMedecineToPharmacy();//додавання ліків 
        void DeleteMedecineFromPharmacyByName();//видалення ліків
        void Recalculation();//видалення прострочений ліків
        void Sale(int discount);//знижка на всі ліки на 10% 
        void OutCheapestMedecineInPharmacy();//виведення найдишевших 
        void OutAllAvalibleNMedecineInPharmacy();//виведення всіх ліків, які є
        void DeleteMedecine(int i); 
};

int main(){
    Pharmacy a;
    int input;
    
    while(1){
        cout << "addMed (1), delMed (2), recalculation (3), sale (4), cheapest (5), outAll (6)\ninp: ";
        cin >> input;
        switch (input)
        {
            case 1: a.AddMedecineToPharmacy(); break;
            case 2: a.DeleteMedecineFromPharmacyByName(); break;
            case 3: a.Recalculation(); break;
            case 4: a.Sale(10); break;
            case 5: a.OutCheapestMedecineInPharmacy(); break;
            case 6: a.OutAllAvalibleNMedecineInPharmacy(); break;
            default: return 0;
        }
    }
}
void Medecine::AddNewMedecine()
{
    cout << "Name: ";
    cin >> name_;
    cout << "Price: ";
    cin >> price_;
    cout << "Quantity: ";
    cin >> quantity_;
    cout << "is_prescription_needed: ";
    cin >> is_prescription_needed_;
    cout << "expirationDate (YYYYMM):";
    cin >> expiration_date_;
    cout << "added \n\n";
}
void Medecine::OutputMedecine()
{
    cout << "Name: ";
    cout << name_ << endl;
    cout << "Price: ";
    cout << price_ << endl;
    cout << "Quantity: ";
    cout << quantity_ << endl;
    cout << "Is_prescription_needed: ";
    cout << is_prescription_needed_ << endl;
    cout << "expirationDate (YYYYMM): ";
    cout << expiration_date_ << endl << endl;
}

void Pharmacy::AddMedecineToPharmacy()
{
    size_++;
    Medecine* temp = new Medecine[size_];
    for(int i = 0; i<size_-1;i++){
      temp[i] = medecine_[i];
    }
    delete[] medecine_;
    medecine_ = temp;
    medecine_[size_-1].AddNewMedecine();
}
void Pharmacy::DeleteMedecineFromPharmacyByName()
{
    int i = 0;
    bool isFound = 0;
    string name;
        cout << "find and delete: ";
        cin >> name;
    while(i <= size_){
        if (i == size_ && !isFound){
            cout << "not found " << name <<endl;
        }
        if(medecine_[i].name_ == name){
            isFound = 1;
            DeleteMedecine(i);
            cout << "\tdeleted " << name << endl;
        }
        i++;
    }
}
void Pharmacy::Recalculation()
{
    int i = 0;
    cout << "Recalculation:" << endl;
    while(i <= size_){
        if(medecine_[i].expiration_date_ <= DATE){
            cout << "\tdeleted " << medecine_[i].name_ << endl;   
            DeleteMedecine(i);
        }
        i++;
    }
}
void Pharmacy::Sale(int discount)
{
    int i = 0;
    while(i < size_){
        medecine_[i].price_ *= (1.0-(discount/100.0));
        i++;
    }
}
void Pharmacy::OutAllAvalibleNMedecineInPharmacy()
{
    int i = 0;
    cout << "\nHere: " << endl;
    while(i < size_){
        medecine_[i].OutputMedecine();
        i ++;
    }
}
void Pharmacy::OutCheapestMedecineInPharmacy()
{
   int min = medecine_[0].price_;
   for(int i = 1;i < size_; i++){
     if(min > medecine_[i].price_){
      min = medecine_[i].price_;
      cout << min << endl;
    }
   }
   for(int i =0;i<size_;i++){
     if(medecine_[i].price_ == min)
      medecine_[i].OutputMedecine();
    }
}
void Pharmacy::DeleteMedecine(int i){
    size_ --;
    for(int j = i; j<size_; j++){
        medecine_[j] = medecine_[j + 1];
    }
 }