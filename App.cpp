#include <fstream>
#include <algorithm>
#include "App.h"

App::App(Aeroporto aeroporto) {
    this->aeroporto=aeroporto;
    cout<<endl<<"Airport created"<<endl<<endl<<"The airport has "<<aeroporto.GetPlanes().size()<<" planes and "<<aeroporto.getnumFLights()<<" flights planned"<<endl<<"There are "<<aeroporto.GetPlanes()[0].getServicesRealizar().size()<<" services of cleaning and maintenance planned"<<endl<<endl;
}

int App::run() {
    int option;
    int counter;
    while (true){
        cout<<"What would you like to do next?"<<endl<<endl<<"1 See full list of flights"<<endl<<"2 See flight by destination"<<endl<<"3 See completed flights"<<endl<<"4 Fly"<<endl<<"5 See every transportation method"<<endl<<"6 See the transportation method that you want"<<endl<<"7 See the cleaning/maintenance services that have been done and are still yet to be done"<<endl<<"8 Exit"<<endl;
        cin>>option;
        if (cin.fail()){
            throw invalid_argument("Please choose a valid number");
        }
        switch(option){
            case 1:
                if (aeroporto.GetPlanes()[0].getPlano().size()==0){
                    cout<<"There are no flights in this airport"<<endl<<endl;
                    break;
                }
                for (int i=0;i<aeroporto.GetPlanes().size();i++){
                    cout<<"Plane "<<i+1 <<" License Plate: "<<aeroporto.GetPlanes()[i].getMatricula()<<" Type: "<<aeroporto.GetPlanes()[i].getTipo()<<endl<<endl;
                    for (int j=0;j<aeroporto.GetPlanes()[i].getPlanoVector().size();j++){
                        Voo v=aeroporto.GetPlanes()[i].getPlanoVector()[j];
                        cout<<"     - Id: "<<v.getNumero()<<" Date: "<<v.getPartida()<<" Origin: "<<v.getOrigem()<<" Destination: "<<v.getDestino()<<" Duration: "<<v.getDuration()<<" ("<<v.ticketsAvailable()<<" tickets available)"<<endl;
                    }
                    cout<<endl;
                }
                continue;
            case 4:
            {
                if (aeroporto.getnumFLights()==0){
                    cout<<"There are no flights available, sorry"<<endl<<endl;
                    cin.clear();
                    break;
                }
                int flight;
                int plane;
                int numTickets;
                string BagOption;
                string checkinOption;
                bool exists=false;
                bool luggage;
                bool checkin;
                cout<<"Which flight would you like to buy a ticket to?"<<" (Pick the number of the flight from the available ones)"<<endl;
                cin>>flight;
                if (cin.fail()){
                    throw invalid_argument("Please choose a valid number");
                }
                for (int i=0;i<aeroporto.GetPlanes().size();i++){
                    for (int j=0;j<aeroporto.GetPlanes()[i].getPlanoVector().size();j++){
                        if (flight==aeroporto.GetPlanes()[i].getPlanoVector()[j].getNumero()){
                            exists=true;
                        }
                    }
                }
                if (exists==false){
                    cout<<"Flight not found, sorry"<<endl<<endl;
                    cin.clear();
                    break;
                }
                exists=false;
                cout<<"Which plane would you like for that flight?"<<"(Pick the number of the plane from the available ones)"<<endl;
                cin>>plane;
                if (cin.fail()){
                    throw invalid_argument("Please choose a valid number");
                }
                for (int i=0;i<aeroporto.GetPlanes()[plane-1].getPlanoVector().size();i++){
                    if (flight==aeroporto.GetPlanes()[plane-1].getPlanoVector()[i].getNumero()){
                        exists=true;
                    }
                }
                if (exists==false){
                    cout<<"That plane does not have that flight scheduled"<<endl<<endl;
                    cin.clear();
                    break;
                }
                if (plane>aeroporto.GetPlanes().size()){
                    cout<<"That plane does not exist, sorry"<<endl<<endl;
                    cin.clear();
                    break;
                }
                Aviao a=aeroporto.GetPlanes()[plane-1];
                Voo v=a.getPlanoVector()[flight-1-counter];
                v.AddRandomP(v.getCapacity());
                cout<<endl<<"There are "<<v.getQueueSize()<<" Passengers ahead of you in the queue to buy the tickets"<<endl<<endl;
                v.BuyTickets();
                cout<<"It's your turn, there are now only "<<v.ticketsAvailable()<<" tickets available"<<endl<<"How many would you like to get?"<<endl;
                cin>>numTickets;
                if (cin.fail()){
                    throw invalid_argument("Please choose a valid number");
                }
                if (numTickets>v.ticketsAvailable()){
                    cout<<"That exceeds the number of tickets available, sorry"<<endl<<endl;
                    break;
                }
                cout<<"Are you going to take luggage with you to the flight? (please type *yes* or *no*)"<<endl;
                cin>>BagOption;
                if (BagOption=="yes" or BagOption=="YES"){
                    luggage=true;
                }
                else if(BagOption=="no" or BagOption=="NO"){
                    luggage=false;
                    checkin=false;
                }
                else{
                    cout<<"That is not a valid option, sorry"<<endl;
                    cin.clear();
                    break;
                }
                Passageiro user(v.getCapacity()-v.ticketsAvailable()+1,numTickets,luggage,checkin);
                v.AddToBuy(user);
                v.BuyTickets();
                if (a.getServicesRealizar().size()>0){

                }
                else{
                    cout<<"There are no services to be made therefore the flight cannot happen"<<endl;
                    cin.clear();
                    break;
                }
                Service service=a.getServicesRealizar().front();
                if (a.isService()){
                    cout<<"It's now boarding time!"<<endl<<"There is currently being performed on the plane a "<<service.getTypeENG()<<" service by our beloved worker "<<service.getFuncionario() <<" which will be over in a bit"<<endl;
                }
                else{
                    cout<<"We were trying to do a maintenance/cleaning service but our dates got mixed up, we apologize for the inconvenience"<<endl;
                    break;
                }
                if (luggage==true){
                    cout<<"In the meantime would you like to use our service to auto checkin your luggage instead of taking it with you to the plane? (please type *yes* or *no*)"<<endl;
                    cin>>checkinOption;
                    if (checkinOption=="yes" or checkinOption=="YES"){
                        checkin=true;
                    }
                    else if(checkinOption=="no" or checkinOption=="NO"){
                        checkin=false;
                    }
                    else{
                        cout<<"That is not a valid option, sorry"<<endl;
                        break;
                    }
                    user.setCheckin(checkin);
                }
                cout<<"The "<<a.getServicesRealizar().front().getTypeENG()<<" service is now done and the passengers may board"<<endl;
                if (luggage==true&&checkin==false){
                    if(user.GetBag().getPeso()>v.getBagWeight()){
                        cout<<"Since the weight of your luggage exceeds the maximum weight per bag of this plane we will have to send it to the auto luggage checkin"<<endl;
                        checkin=true;
                        user.setCheckin(checkin);
                    }
                }
                v.addPassageiro(user);
                a.setVoo(v);
                cout<<"The flight is about to begin"<<endl;
                if (a.Fly(v.getPartida(),v.getOrigem(),v.getDestino(),checkin)){
                    cout<<"----------Currently in the air--------"<<endl<<endl;
                    cout<<"----------Currently in the air--------"<<endl<<endl;
                    cout<<"----------Currently in the air--------"<<endl<<endl;
                    cout<<"----------Currently in the air--------"<<endl<<endl;
                    cout<<"----------Currently in the air--------"<<endl<<endl;
                    cout<<"----------Currently in the air--------"<<endl<<endl;
                    cout<<"----------Currently in the air--------"<<endl<<endl;
                    cout<<"The flight was successful"<<endl<<endl;
                }
                else{
                    cout<<"Something went wrong and the plane could not take off, we apologize for this inconvenience"<<endl;
                    break;
                }
                cout<<"All the bags have been taken out of the car and returned to their owners"<<endl<<endl;
                aeroporto.setPlane(plane,a);
                counter+=flight;
            }
                continue;
            case 5:
                aeroporto.printLocais();
                continue;
            case 6:
            {
                LocalTransporte previous("", 0, {}, true), next("",0,{},true);
                string tipo;
                float distance;
                bool valid;
                cout<<"Please write the type of transportation that you would like to use (*metro*, *autocarro*, *comboio*)"<<endl;
                cin>>tipo;
                if(tipo!="metro" && tipo!="autocarro" && tipo!="comboio" && tipo!=""){
                    cout<<"Invalid method of transportation"<<endl;
                    cin.clear();
                    break;
                }
                cout<<"Please write your preferred distance to find the "<<tipo<<" that you are looking for (can be a non integer)"<<endl;
                cin>>distance;
                if (cin.fail()){
                    cin.clear();
                    cout<<"Invalid distance"<<endl;
                    break;
                }
                vector<float> res=aeroporto.consultLocais(tipo, distance, previous, next);
                if(!res.empty()) {
                    cout << "Horario: ";
                    for (auto value: res)
                        cout << value << "    ";
                }
                cout<<endl;
            }
                cout<<endl;
                continue;
            case 8:
                save();
                return 0;
            case 2:
            {
                string destination;
                bool valid=false;
                cout<<"Please write the destination to see the flights"<<endl;
                cin>>destination;
                if (aeroporto.GetPlanes()[0].printVoo(destination)){
                    valid=true;
                }
                if (valid==false){
                    cout<<"There is no flight to that destination"<<endl<<endl;
                    break;
                }
            }
                cout<<endl;
                continue;
            case 7:
                aeroporto.servicePrinter();
                continue;
            case 3:
                if (aeroporto.GetPlanes()[0].getDoneFlights().size()==0){
                    cout<<"There have been no completed flights so far"<<endl<<endl;
                    break;
                }
                aeroporto.DoneFlightsPrinter();
                cout<<endl;
            default:
                continue;
        }
    }


}

void App::save() {
    vector<Voo> V=aeroporto.GetPlanes()[0].getPlanoVector();
    queue<Service> S=aeroporto.GetPlanes()[0].getServicesRealizar();
    queue<Service> DoneS=aeroporto.GetPlanes()[0].getServicesRealizados();
    ofstream file;

    file.open("VooDone.txt");
    if (!(file.is_open())){
        throw invalid_argument("File not found");
    }
    vector<Voo> temp;
    for (int i=0;i<aeroporto.GetPlanes().size();i++){
        for (int j=0;j<aeroporto.GetPlanes()[i].getDoneFlights().size();j++){
            temp.push_back(aeroporto.GetPlanes()[i].getDoneFlights()[j]);
        }
    }
    sort(temp.begin(),temp.end());
    for (int i=0;i<temp.size();i++){
        if (temp[i].getNumero()<10){
            file<<"0"<<temp[i].getNumero()<<" "<<temp[i].getPartida()<<" "<<"0"<<temp[i].getDuration()<<" "<<temp[i].getOrigem()<<" "<<temp[i].getDestino()<<endl;
        }
        else{
            file<<temp[i].getNumero()<<" "<<temp[i].getPartida()<<" "<<"0"<<temp[i].getDuration()<<" "<<temp[i].getOrigem()<<" "<<temp[i].getDestino()<<endl;
        }
    }
    file.close();
    file.open("Voo.txt");
    if (!(file.is_open())){
        throw invalid_argument("File not found");
    }
    temp.clear();
    for (int i=0;i<aeroporto.GetPlanes().size();i++){
        for (int j=0;j<aeroporto.GetPlanes()[i].getPlanoVector().size();j++){
            temp.push_back(aeroporto.GetPlanes()[i].getPlanoVector()[j]);
        }
    }
    sort(temp.begin(),temp.end());
    for (int i=0;i<temp.size();i++){
        if (temp[i].getNumero()<10){
            file<<"0"<<temp[i].getNumero()<<" "<<temp[i].getPartida()<<" "<<"0"<<temp[i].getDuration()<<" "<<temp[i].getOrigem()<<" "<<temp[i].getDestino()<<endl;
        }
        else{
            file<<temp[i].getNumero()<<" "<<temp[i].getPartida()<<" "<<"0"<<temp[i].getDuration()<<" "<<temp[i].getOrigem()<<" "<<temp[i].getDestino()<<endl;
        }
    }
    file.close();

    file.open("ServiceDone.txt");
    if (!(file.is_open())){
        throw invalid_argument("File not found");
    }
    vector<Service> temp2;
    queue<Service> sv=aeroporto.GetPlanes()[0].getServicesRealizados();
    while( sv.size()>0){
        temp2.push_back(sv.front());
        sv.pop();
    }
    sort(temp2.begin(),temp2.end());
    for (int i=0;i<temp2.size();i++){
        file<<temp2[i].getTypeENG().substr(0,1)<<" "<<temp2[i].getData()<<" "<<temp2[i].getFuncionario()<<endl;
    }
    file.close();
    file.open("service.txt");
    if (!(file.is_open())){
        throw invalid_argument("File not found");
    }
    temp2.clear();
    queue<Service> sv2=aeroporto.GetPlanes()[0].getServicesRealizar();
    while( sv2.size()>0){
        temp2.push_back(sv2.front());
        sv2.pop();
    }
    sort(temp2.begin(),temp2.end());
    for (int i=0;i<temp2.size();i++){
        file<<temp2[i].getTypeENG().substr(0,1)<<" "<<temp2[i].getData()<<" "<<temp2[i].getFuncionario()<<endl;
    }
    file.close();


}
