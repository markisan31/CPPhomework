//
//  main.cpp
//  LisaYlesanne0812_02
//
//  Created by Mark Kalda on 08.12.2020.
//

#include <iostream>
#include <string>
#include <vector>


class Toiduaine {
protected:
    std::string nimetus;
    double vp, rp, sp; //protsentides
public:
    Toiduaine(std::string name, double valgus, double rasv, double sysivesinik){
        this -> nimetus = name;
        this -> vp = valgus;
        this -> rp = rasv;
        this -> sp = sysivesinik;
        if (vp + rp + sp > 100){
            std::cout << "Kontrollige yle " << nimetus << "! Valguse, rasva ja sysivesiniku protsentiline kogum ei tohi yllatada 100%" << std::endl;
        }
    }
    
    Toiduaine(){
        
    }
    
    void setVp(double valgus){
        this -> vp = valgus;
    }
    
    void setRp(double rasv){
        this -> rp = rasv;
    }
    
    void setSp(double sysivesinik){
        this -> sp = sysivesinik;
    }
    
    double getVp(){
        return vp;
    }
    
    double getRp(){
        return rp;
    }
    
    double getSp(){
        return sp;
    }
    
    std::string getNimetus(){
        return nimetus;
    }
    
};

class Toidukomponent : public Toiduaine{
private:
    Toiduaine td;
    double kogus; //grammides
    Toidukomponent* tk;
public:
    Toidukomponent(){
        
    }
    
    Toidukomponent (Toiduaine a){
        this -> td = a;
    }
    
    Toidukomponent (Toiduaine a, double g){
        this -> td = a;
        this -> kogus = g;
    }
    
    Toiduaine getToiduaine(){
        return td;
    }
        
    double getVp(){
        return kogus * td.getVp() / 100;
    }
    
    double getRp(){
        return kogus * td.getRp() / 100;
    }
    
    double getSp(){
         return kogus * td.getSp() / 100;
    }
    
    double getKogus(){
        return kogus;
    }
    
};

class Toiduportsioon : public Toidukomponent {
private:
    std::vector <Toidukomponent> toidukomponentideList;
public:
    
    Toiduportsioon(){
        
    }
    
    Toiduportsioon(std::vector <Toidukomponent> listOfTK){
        this -> toidukomponentideList = listOfTK;
    }
    
    double getAllMass (){
        double allMass = 0;
        for (Toidukomponent a : toidukomponentideList){
            allMass = allMass + a.getKogus();
        }
        return allMass;
    }
    
    double getKoguValguseMass(){
        double valguseMass = 0;
        for (Toidukomponent a : toidukomponentideList){
            valguseMass = valguseMass + a.getVp();
        }
        return valguseMass;
    }
    
    double getKoguRasvaMass(){
        double rasvaMass = 0;
        for (Toidukomponent a : toidukomponentideList){
            rasvaMass = rasvaMass + a.getRp();
        }
        return rasvaMass;
    }
    
    double getKoguSysivesinikuMass(){
        double sysivesinikuMass = 0;
        for (Toidukomponent a : toidukomponentideList){
            sysivesinikuMass = sysivesinikuMass + a.getSp();
        }
        return sysivesinikuMass;
    }
    
    double getToidukomponentiKogusByToiduportsiooniMass(double soovitudPortsioniMass, Toiduaine ta){
        double konkreetseKomponendiMass = 0;
        for (Toidukomponent a : toidukomponentideList){
            if (ta.getNimetus() == a.getToiduaine().getNimetus()){
                konkreetseKomponendiMass = a.getKogus();
            }
        }
        double komponendiProtsentSisaldusKoguPortsiooniMassist = konkreetseKomponendiMass / getAllMass();
        
        return soovitudPortsioniMass * komponendiProtsentSisaldusKoguPortsiooniMassist;
    }
        
};

int main(int argc, const char * argv[]) {
    Toiduaine piim ("piim", 32, 50, 18);
    Toiduaine kartul ("kartul", 10, 30, 60);
    Toiduaine seened ("seened", 80, 1.2, 10);
    
    Toidukomponent kogumPiima(piim, 300);
    Toidukomponent kogumKartuleid(kartul, 500);
    Toidukomponent kogumSeeni(seened, 127);
    
    std::cout << "Kartuli kogumass on: " << kogumKartuleid.getKogus() << "g" << std::endl;
    std::cout << kogumKartuleid.getKogus()<< "g kartuleid sisaldab: "<< kogumKartuleid.getVp() << "g valguse"<< std::endl;
    std::cout << kogumKartuleid.getKogus()<< "g kartuleid sisaldab: "<< kogumKartuleid.getRp() << "g rasva"<< std::endl;
    std::cout << kogumKartuleid.getKogus()<< "g kartuleid sisaldab: "<< kogumKartuleid.getSp() << "g sysivesinikke"<< std::endl;
    
    std::cout << "------------------" << std::endl;
    
    std::cout << "Piima kogumass on: " << kogumPiima.getKogus() << "g" << std::endl;
    std::cout << kogumPiima.getKogus()<< "g piima sisaldab: "<< kogumPiima.getVp() << "g valguse"<< std::endl;
    std::cout << kogumPiima.getKogus()<< "g piima sisaldab: "<< kogumPiima.getRp() << "g rasva"<< std::endl;
    std::cout << kogumPiima.getKogus()<< "g piima sisaldab: "<< kogumPiima.getSp() << "g sysivesinikke"<< std::endl;
    
    std::cout << "------------------" << std::endl;
    
    std::vector<Toidukomponent> TKlist = {kogumPiima, kogumKartuleid, kogumSeeni};
    
    Toiduportsioon ports (TKlist);
    
    std::cout << "Portsiooni mass on: " << ports.getAllMass() << "g" << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << "Portsiooni valguse sisaldus on: " << ports.getKoguValguseMass() << "g" << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << "100 grammi portsiooni jaoks, meil on vaja umbes " << ports.getToidukomponentiKogusByToiduportsiooniMass(100, piim) << "g "<< piim.getNimetus() << std::endl;
    

    return 0;
}
