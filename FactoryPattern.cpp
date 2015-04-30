#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

class MsgLog{
public:
	virtual void logging(string)=0;
	std::string Log;
	virtual ~MsgLog(){
		
	}
};

class DbLog:public MsgLog{
public: 
	void logging(string msg){
		std::string Lmsg = "DBLog: ";
		Lmsg.append(msg);
		Log.append(Lmsg);
	}	~DbLog(){
		
	}
};
class ConfigLog:public MsgLog{
public: 
	void logging(string msg){
		std::string Lmsg = "ConfigLog: ";
		Lmsg.append(msg);
		Log.append(Lmsg);
	}
	~ConfigLog(){
		
	}
};
class ServiceLog:public MsgLog{
	void logging(string msg){
		cout << "ServiceLog: new Service log message." <<msg<<endl;
	}
	~ServiceLog(){
		
	}
};

class ProductLogFactory{
public:
	MsgLog *getLog(string source){
		MsgLog *Log;
		if(source.compare("db") == 0){
			//cout << "This is DbLog\n";
			Log = new DbLog;
			return Log;
		}else if(source.compare("config") == 0){
			//cout << "This is Config Log\n";
			Log = new ConfigLog;
			return Log;
		}else{
			//cout << "This is Service Log\n";
			Log = new ServiceLog;
			return Log;
		}
	}
};

int main(){
	ProductLogFactory *pf = new ProductLogFactory();
	MsgLog *L1 = pf->getLog("config");
	L1->logging("Factory reset completed.\n");
	L1->logging("Provisioning completed.\n");
	MsgLog *L2 = pf->getLog("db");
	L2->logging("Database table created.\n");
	L2->logging("Database table-2 created.\n");
	cout << L1->Log;
	cout << L2->Log;
	delete L1;
	delete L2;
	delete pf;
}
