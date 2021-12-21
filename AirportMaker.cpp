#include "AirportMaker.h"
/**
 * Creates an aeroport object and sets the airport of the object to it
 */
AirportMaker::AirportMaker() {
    Aeroporto airport;
    this->airport=airport;

}

/**
 * Adds the planes and the transport locals to the airport
 */
void AirportMaker::FillAirport() {
    vector<Aviao> planes=PlaneMaker();
    for (int i=0;i<planes.size();i++){
        airport.addPlane(planes[i]);
    }
    vector<LocalTransporte> locais=LocaisAdder();
    for (int i=0;i<locais.size();i++){
        airport.addLocal(locais[i]);
    }
}

/**
 * Creates the planes by reading information from a file with the details of each plane
 * @return vector of planes
 */
vector<Aviao> AirportMaker::PlaneMaker() {
    vector<Aviao> planes;
    string PlaneLine;
    ifstream file;
    file.open("plane.txt");
    if (!(file.is_open())){
        throw invalid_argument("File not found");
    }
    while(getline(file,PlaneLine)){
        int capacidade,Baglimit;
        if (PlaneLine.substr(9,1)=="A"){
            Baglimit=40;
            capacidade=200;
        }
        if (PlaneLine.substr(9,1)=="B"){
            Baglimit=20;
            capacidade=100;
        }
        if (PlaneLine.substr(9,1)=="S"){
            Baglimit=60;
            capacidade=400;
        }
        list<Voo> voos=VoosMaker(capacidade,Baglimit);
        queue<Service> services=ServicesMaker();
        vector<Voo> Done=DoneVooMaker();
        Aviao A(PlaneLine.substr(0,8),PlaneLine.substr(9,4), voos,services);
        for (int i=0;i<Done.size();i++){
            A.addplanoDone(Done[i]);
        }
        queue<Service> s2=DoneServiceMaker();
        A.setServices(services,s2);
        planes.push_back(A);
    }
    return planes;
}
/**
 * Creates the flights by reading information from a file with the details of each flight
 * @param capacidade max capacity of the plane
 * @param BagLimit max bag weight for each bag
 * @return list of flights
 */
list<Voo> AirportMaker::VoosMaker(int capacidade, int BagLimit) {
    list<Voo> voos;
    string VooLine;
    int Nodupe=0;
    ifstream file;
    file.open("Voo.txt");
    if (!(file.is_open())){
        throw invalid_argument("File not found");
    }
    while(getline(file,VooLine)){
        string n=VooLine.substr(0,2),d=VooLine.substr(14,2),o,s,os;
        int x,y,p;
        stringstream n1(n), d1(d);
        n1>>x;
        if (x==Nodupe){
            continue;
        }
        Nodupe=x;
        d1>>y;
        os=VooLine.substr(17,VooLine.length());
        for (int i=0;i<os.size();i++){
            if (os.substr(i,1)==" "){
                p=i;
            }
        }
        o=os.substr(0,p);
        s=os.substr(p+1,os.length());
        Voo v(x,VooLine.substr(3,10),y,o,s,capacidade,BagLimit);
        voos.push_back(v);
    }
    return voos;
}

/**
 * Creates the services by reading the information from a file with the details of each service
 * @return queue of services
 */
queue<Service> AirportMaker::ServicesMaker() {
    queue<Service> services;
    string ServiceLine;
    ifstream file;
    file.open("service.txt");
    if (!(file.is_open())){
        throw invalid_argument("File not found");
    }
    while(getline(file,ServiceLine)){
        Service s(ServiceLine.substr(0,1),ServiceLine.substr(2,10),ServiceLine.substr(13,ServiceLine.length()));
        services.push(s);
    }
    return services;
}

/**
 * Gets the airport object
 * @return object of the class Aeroporto
 */
Aeroporto AirportMaker::GetAeroporto() {
    return this->airport;
}

/**
 * Creates the transport locals by reading information from a file with the details of each local
 * @return
 */
vector<LocalTransporte> AirportMaker::LocaisAdder() {
    vector<LocalTransporte> locais;
    string TransporteLine;
    bool availability;
    ifstream file;
    file.open("transportes.txt");
    if (!(file.is_open())){
        throw invalid_argument("File not found");
    }
    while(getline(file,TransporteLine)){
        int p;
        for (int i=0;i<TransporteLine.length();i++){
            if (TransporteLine.substr(i,1)==" "){
                p=i;
                break;
            }
        }
        string tipo=TransporteLine.substr(0,p);
        TransporteLine=TransporteLine.substr(p+1,TransporteLine.length());
        for (int i=0;i<TransporteLine.length();i++){
            if (TransporteLine.substr(i,1)==" "){
                p=i;
                break;
            }
        }
        string distance=TransporteLine.substr(0,p);
        TransporteLine=TransporteLine.substr(p+1,TransporteLine.length());
        if (TransporteLine=="true"){
            availability=true;
        }
        else{
            availability=false;
        }
        float d=stof(distance);
        vector<float> h=GetHorarios(tipo);
        LocalTransporte l(tipo,d,h,availability);
        locais.push_back(l);
    }

    return locais;
}

vector<float> AirportMaker::GetHorarios(string tipo) {
    int type;
    if (tipo=="metro"){
        type=1;
    }
    if (tipo=="comboio"){
        type=2;
    }
    if (tipo=="autocarro"){
        type=3;
    }
    int itcounter=0;
    vector<float> horarios;
    string hLine;
    ifstream file;
    file.open("horarios.txt");
    if (!(file.is_open())){
        throw invalid_argument("File not found");
    }
    while(getline(file,hLine)){
        int p;
        int counter=0;
        for (int i=0;i<hLine.length();i++){
            if (hLine.substr(i,1)==" "){
                counter+=1;
            }
        }
        while (counter>0){
            for (int i=0;i<hLine.length();i++){
                if (hLine.substr(i,1)==" "){
                    p=i;
                    break;
                }
            }
            counter-=1;
            string s1=hLine.substr(0,p);
            float f1=stof(s1);
            horarios.push_back(f1);
            hLine=hLine.substr(p+1,hLine.length());

        }
        string s2=hLine;
        float f2=stof(s2);
        itcounter+=1;
        horarios.push_back(f2);
        if (type==itcounter){
            break;
        }
        else{
            horarios.clear();
        }
    }
    return horarios;
}

/**
 * Creates the flights already done by reading information from a file with the details of each flight done
 * @return vector of flights done
 */
vector<Voo> AirportMaker::DoneVooMaker() {
    vector<Voo> voos;
    string VooLine;
    int Nodupe=0;
    ifstream file;
    file.open("VooDone.txt");
    if (!(file.is_open())){
        throw invalid_argument("File not found");
    }
    while(getline(file,VooLine)){
        string n=VooLine.substr(0,2),d=VooLine.substr(14,2),o,s,os;
        int x,y,p;
        stringstream n1(n), d1(d);
        n1>>x;
        if (x==Nodupe){
            continue;
        }
        Nodupe=x;
        d1>>y;
        os=VooLine.substr(17,VooLine.length());
        for (int i=0;i<os.size();i++){
            if (os.substr(i,1)==" "){
                p=i;
            }
        }
        o=os.substr(0,p);
        s=os.substr(p+1,os.length());
        Voo v(x,VooLine.substr(3,10),y,o,s,100,100);
        voos.push_back(v);
    }
    return voos;
}

/**
 * Creates the services already done by reading information from a file with the details of each service done
 * @return queue of services already done
 */
queue<Service> AirportMaker::DoneServiceMaker() {
    queue<Service> services;
    string ServiceLine;
    ifstream file;
    file.open("ServiceDone.txt");
    if (!(file.is_open())){
        throw invalid_argument("File not found");
    }
    while(getline(file,ServiceLine)){
        Service s(ServiceLine.substr(0,1),ServiceLine.substr(2,10),ServiceLine.substr(13,ServiceLine.length()));
        services.push(s);
    }
    return services;
}
