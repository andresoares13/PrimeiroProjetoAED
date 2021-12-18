#include "App.h"

App::App(Aeroporto aeroporto) {
    this->aeroporto=aeroporto;
    cout<<endl<<"Airport created"<<endl<<endl<<"The airport has "<<aeroporto.GetPlanes().size()<<" planes and "<<aeroporto.getnumFLights()<<" flights planned"<<endl<<"There are "<<aeroporto.getnumServices()<<" services of cleaning and maintenance planned"<<endl<<endl;
}

int App::run() {
    int option;
    while (true){
        cout<<"What would you like to do next?"<<endl<<endl<<"1 See list of flights (by plane)"<<endl<<"2 Fly"<<endl<<"3 Exit"<<endl;
        cin>>option;
        if (cin.fail()){
            throw invalid_argument("Please choose a valid number");
        }
        switch(option){
            case 1:
                for (int i=0;i<aeroporto.GetPlanes().size();i++){
                    cout<<i+1 <<" License Plate: "<<aeroporto.GetPlanes()[i].getMatricula()<<" Type: "<<aeroporto.GetPlanes()[i].getTipo()<<endl<<endl;
                    for (int j=0;j<aeroporto.GetPlanes()[0].getPlanoVector().size();j++){
                        Voo v=aeroporto.GetPlanes()[0].getPlanoVector()[j];
                        cout<<"     - Date: "<<v.getPartida()<<" Origin: "<<v.getOrigem()<<" Destination: "<<v.getDestino()<<" Duration: "<<v.getDuration()<<endl;
                    }
                    cout<<endl;
                }
                continue;
            case 2:
                break;
            case 3:
                return 0;
            default:
                continue;
        }
    }


}
