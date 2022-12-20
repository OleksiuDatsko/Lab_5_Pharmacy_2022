#include <iostream>
using namespace std;

#define DATE 202211 //YYYYMM

class Medecine
{
public:
  string name = "";
  int price = 0;
  int quantity = 0;
  bool isPrescriptionNeeded = 0;
  int expirationDate = 0; //YYYYMM

  void SetNewMedecine();
  void OutputMedecine();
};
class Pharmacy
{
  private:
    int size = 0;
    Medecine* medecine = new Medecine[size]; //асортимент ліків
  public:
    void AddMedecineToPharmacy();//додавання ліків 
    void DeleteMedecineFromPharmacy();//видалення ліків
    void Recalculation();//видалення прострочений ліків
    void Sale(int discount);//знижка на всі ліки на 10% 
    void CheapestMedecineInPharmacy();//виведення найдишевших 
    void OutAllAvailableMedecineInPharmacy();//виведення всіх ліків, які є

    void DeleteMedecine(int i); 
};

int main(){
  Pharmacy pharmacy;
  int input;
  
  while(1){
  cout << "addMed (1), delMed (2), recalculation (3), sale (4), cheapest (5), outAll (6)\ninp: ";
  cin >> input;
  switch (input)
    {
      case 1: pharmacy.AddMedecineToPharmacy(); break;
      case 2: pharmacy.DeleteMedecineFromPharmacy(); break;
      case 3: pharmacy.Recalculation(); break;
      case 4: pharmacy.Sale(10); break;
      case 5: pharmacy.CheapestMedecineInPharmacy(); break;
      case 6: pharmacy.OutAllAvailableMedecineInPharmacy(); break;
      default: return 0;
    }
  }
}
void Medecine::SetNewMedecine()
{
  cout << "Name: ";
  cin >> name;
  cout << "Price: ";
  cin >> price;
  cout << "Quantity: ";
  cin >> quantity;
  cout << "IsPrescriptionNeeded: ";
  cin >> isPrescriptionNeeded;
  cout << "expirationDate (YYYYMM):";
  cin >> expirationDate;
  cout << "added \n\n";
}

void Medecine::OutputMedecine()
{
  cout << "Name: ";
  cout << name << endl;
  cout << "Price: ";
  cout << price << endl;
  cout << "Quantity: ";
  cout << quantity << endl;
  cout << "IsPrescriptionNeeded: ";
  cout << isPrescriptionNeeded << endl;
  cout << "expirationDate (YYYYMM): ";
  cout << expirationDate << endl << endl;
}

void Pharmacy::AddMedecineToPharmacy()
{
  size++;
  Medecine* temp = new Medecine[size];
  for(int i = 0; i<size-1;i++){
    temp[i] = medecine[i];
  }
  delete[] medecine;
  medecine = temp;
  medecine[size-1].SetNewMedecine();
}

void Pharmacy::DeleteMedecineFromPharmacy()
{
  int i = 0;
  bool isFound = 0;
  string name;
    cout << "find and delete: ";
    cin >> name;
  while(i <= size){
    if (i == size && !isFound){
      cout << "not found " << name <<endl;
    }
    if(medecine[i].name == name){
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
  while(i <= size){
    if(medecine[i].expirationDate <= DATE){
      cout << "\tdeleted " << medecine[i].name << endl;   
      DeleteMedecine(i);
    }
    i++;
  }
}

void Pharmacy::Sale(int discount)
{
  int i = 0;
  while(i < size){
    medecine[i].price *= (1-(100.0/discount));
    i++;
  }
}

void Pharmacy::OutAllAvailableMedecineInPharmacy()
{
  int i = 0;
  cout << "\nHere: " << endl;
  while(i < size){
    medecine[i].OutputMedecine();
    i ++;
  }
}

void Pharmacy::CheapestMedecineInPharmacy()
{
  int min = medecine[0].price;
  for(int i = 1;i < size; i++){
    if(min > medecine[i].price){
      min = medecine[i].price;
      cout << min << endl;
    }
  }
  for(int i =0;i<size;i++){
    if(medecine[i].price == min)
      medecine[i].OutputMedecine();
  }
}

void Pharmacy::DeleteMedecine(int i){
  size --;
  for(int j = i; j<size; j++){
    medecine[j] = medecine[j + 1];
  }
 }