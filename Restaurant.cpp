#include "main.h"

class imp_res : public Restaurant
{
	public:
		imp_res() {};
		class cusbiduoi {
			private:
			int count;
			customer* top;
            public:
			cusbiduoi() {
				this->top=nullptr;
				this->count=0;
			}
			~cusbiduoi() {
				customer* newcustomer;
				while (this->top!=nullptr) {
					newcustomer=this->top;
					this->top=this->top->next;
					delete newcustomer;
				}
				this->count=0;
			}
			void pushcus(string name, int energy) {
                 customer*newcustomer=new customer(name, energy, nullptr,nullptr);
				 newcustomer->next=this->top;
				 this->top=newcustomer;
				 this->count++;
			}
			void printcus() {
				customer*newcustomer=this->top;
				while(newcustomer!=nullptr) {
					newcustomer->print();
					newcustomer=newcustomer->next;
				}
				delete newcustomer;
			}
		};
        class QUEUE{
            private: 
		        customer* front;
			    customer* rear;
				int count;
				int countoanlinh;
				int countchuthuatsu;
			public:
			QUEUE() {
				this->front=nullptr;
				this->rear=nullptr; 
				this->count=0;
				this->countoanlinh=0;
				this->countchuthuatsu=0;
			}
			~QUEUE() {
				if(this->count==1) {
			       customer* newcus = this->front;
					this->rear=nullptr;
					this->front=nullptr;
					delete newcus;
				}
				while(this->count!=0) {
					customer* newcus=this->front;
					this->front=this->front->next;
					delete newcus;
					this->count--;
				}
			}
			void EnQueue(string name, int energy) {
				customer* newcustomer= new customer(name,energy,nullptr,nullptr);
				if(this->count==0) {
					this->front=newcustomer;
					this->rear=newcustomer;
				}
				else {
					this->rear->next=newcustomer;
					this->rear=newcustomer;
				}
				if(energy>0) this->countchuthuatsu++;
				else this->countoanlinh++;
				this->count++;
			}

			void DeQueue() {
				customer*newcustomer = this->front;
				if(this->count==1) {	
					this->front=nullptr;
					this->rear=nullptr;
				}
				else {
					this->front = this->front->next;
				}
				delete newcustomer;
				this->count--;
			}
			string getnameQUEUE() {
				return this->front->name;
			}
			int getenergyQUEUE() {
				return this->front->energy;
			}
			int getenergypositive() {
				int pos=0;
				customer* get=this->front;
				while(get!=nullptr) {
					if(get->energy>0) pos=pos+get->energy;
					get=get->next;
				}
				delete get;
				return pos;
			}
			int getenergynegative() {
				int pos=0;
				customer* get=this->front;
				while(get!=nullptr) {
					if(get->energy<0) pos=pos+get->energy;
					get=get->next;
				}
				delete get;
				return pos;
			}
            void DeQueueCURRENT(string name) {
				if(this->count==1) {
					this->front=nullptr;
					this->rear=nullptr;
				}
				else {
				    customer* newcustomer = this->front;
					if(newcustomer->name==name) {
						this->front=this->front->next;
						delete newcustomer;
						
					}
					else {
				        while(newcustomer->next->name!=name) {
                            newcustomer=newcustomer->next;
				        }
						if(newcustomer->next->next==nullptr) {
							//delete newcustomer->next;
							this->rear=newcustomer;
						}
						else {
							//delete newcustomer->next;
							newcustomer->next=newcustomer->next->next;
						    }	
						}	
					// newcustomer->next=nullptr;
					// newcustomer->prev=nullptr;
					// delete newcustomer;
				}
				this->count--;
			}
			
            bool checkname(string name) {
                customer* newfront = this->front;
				while(newfront!=nullptr) {
					if (newfront->name==name) 
					{
						delete newfront;
						return 1;
					}
					newfront= newfront->next;
				}
				delete newfront;
				return 0;
			}
			customer* getcustomerhaveenergyMax() {
				if(this->count==0) return 0;
				else if(this->count==1) return this->front;
				else {
					customer* customerreturn=this->front;
					customer* newfront=this->front;
					int returnmax=abs(this->front->energy);
					while(newfront!=nullptr) {
						if(returnmax<=abs(newfront->energy)) {
							returnmax=abs(newfront->energy);
							customerreturn=newfront;
						}
			            newfront=newfront->next;
					}
					delete newfront;
                    return customerreturn;
				}
				
			}

			customer*getcustomernumber(int n) {
				customer* newfornt= this->front;
				while(n--) {
					newfornt=newfornt->next;
				}
				return newfornt;
			}

			int getcountQueue() {
				return this->count;
			}
			void printQUEUE() {
				if (this->count==0) return;
				int num=this->count;
				customer* p = this->front;
				while(num--) {
					p->print();
					p=p->next;
				}
				delete p;
			}
			int getnumberofcustomer(customer* n) {
				customer* p=this->front;
				int count=0;
				while(p!=n) {
					p=p->next;
					count++;
				}
				delete p;
				return count;
			}
			void swapcustomer(customer* a, customer* b) {
				customer* temp = new customer(a->name,a->energy,nullptr,nullptr);
				a->name=b->name;
				a->energy=b->energy;
				b->name=temp->name;
				b->energy=temp->energy;
				delete temp;
			}
			int getcountthuatsu() {
				return this->countchuthuatsu;
			}
			int getcountoanlinh() {
				return this->countoanlinh;
			}
		};
        class TIMEQUEUE{
            private: 
		        customer* front;
			    customer* rear;
				int count;
				int countchuthuatsu;
				int countoanlinh;
			public:
			TIMEQUEUE() {
				this->front=nullptr;
				this->rear=nullptr; 
				this->count=0;
				this->countchuthuatsu=0;
				this->countoanlinh=0;
			}
			~TIMEQUEUE() {
				if(this->count==1) {
			       customer* newcus = this->front;
					this->rear=nullptr;
					this->front=nullptr;
					delete newcus;
				}
				while(this->count!=0) {
					customer* newcus=this->front;
					this->front=this->front->next;
					delete newcus;
				}
				this->count=this->countchuthuatsu=this->countoanlinh=0;
			}
			void EnTIMEQUEUE(string name, int energy) {
				customer* newcustomer= new customer(name,energy,nullptr,nullptr);
				if(this->count==0) {
					this->front=newcustomer;
				}
				else {
					this->rear->next=newcustomer;
				}
				this->rear=newcustomer;
				this->count++;
				if(energy>0) countchuthuatsu++;
				else countoanlinh++;
			}
			void DeTIMEQUEUE() {
				customer*newcustomer = this->front;
				if(this->count==1) {
					if(this->front->energy>0) countchuthuatsu--;
					else countoanlinh--;
					this->front=nullptr;
					this->rear=nullptr;
				}
				else {
					if(this->front->energy>0) countchuthuatsu--;
					else countoanlinh--;
					this->front = this->front->next;
				}
				delete newcustomer;
					this->count--;
			}
            void DeTIMEQUEUECURRENT(string name) {
				if(this->count==1) {
					if(this->front->energy>0) countchuthuatsu--;
					else countoanlinh--;
					this->front=nullptr;
					this->rear=nullptr;
				}
				else {
				    customer* newcustomer = this->front;
					if(newcustomer->name==name) {
						if(this->front->energy>0) countchuthuatsu--;
					    else countoanlinh--;
						delete newcustomer;
						newcustomer=newcustomer->next;
						this->front=newcustomer;
					}
					else {
				        while(newcustomer->next->name!=name) {
                            newcustomer=newcustomer->next;
				        }
                        if(newcustomer->next->next==nullptr) {
							delete newcustomer->next;
							this->rear=newcustomer;
						}
						else {
							delete newcustomer->next;
							newcustomer->next=newcustomer->next->next;
						    }	
						}	
				}
				this->count--;
			}
			int getcountTIMEQUEUE() {
				return this->count;
			}
			bool checkthutuQUEUE(customer*n1, customer*n2) {
				int countn1=0;
				int countn2=0;
				customer*newn1=this->front;
				customer*newn2=this->front;
				while(newn1->name!=n1->name) {
					newn1=newn1->next;
					countn1++;
				}
				while(newn2->name!=n2->name) {
					newn2=newn2->next;
					countn2++;
				}
				delete newn1;
				delete newn2;
				if(countn1<countn2) return 1;
				return 0;
			}
			void printTIMEQUEUE() {
				customer* p = this->front;
				while(p!=nullptr) {
					p->print();
					p=p->next;
				}
				delete p;
			}
			customer* XoaOanLinh() {
				customer* p = this->front;
				while(p!=nullptr) {
					if(p->energy<0) break;
					p=p->next;
				}
				customer* newp = p;
				DeTIMEQUEUECURRENT(p->name);
				delete p;
				return newp;
			}
			customer* XoaChuThuatSu() {
				customer*p=this->front;
				while(p!=nullptr) {
					if(p->energy>0) break;
					p=p->next;
				}
				customer*newp = p;
				DeTIMEQUEUECURRENT(p->name);
				delete p;
				return newp;
			}
			int getoanlinhtrongqueue() {
				return this->countoanlinh;
			}
			int getchuthuatsutrongqueue() {
				return this->countchuthuatsu;
			}
		};
		class TIMECUS {
			private:
			int count;
			int countoanlinh;
			int countchuthuatsu;
			customer* front;
			customer* rear;
			public:
			TIMECUS() {
				this->count=0;
				this->countchuthuatsu=0;
				this->countoanlinh=0;
				this->front=nullptr;
				this->rear=nullptr;
			}
			~TIMECUS() {
				if(this->count==1) {
			       customer* newcus = this->front;
					this->rear=nullptr;
					this->front=nullptr;
					delete newcus;
				}
				while(this->count!=0) {
					customer* newcus=this->front;
					this->front=this->front->next;
					delete newcus;
					this->count--;
				}
			}
			void ENTIMECUS(string name, int energy) {
				customer* newcustomer= new customer(name,energy,nullptr,nullptr);
				if(this->count==0) {
					this->front=newcustomer;
				}
				else {
					this->rear->next=newcustomer;
				}
				this->rear=newcustomer;
				if(energy>0) this->countchuthuatsu++;
				else this->countoanlinh++;
 				this->count++;
			}
			void DETIMECUS() {
				customer*newcustomer = this->front;
				if(this->front->energy>0) countchuthuatsu--;
				else countoanlinh--;
				if(this->count==1) {
					delete newcustomer;
					this->front=nullptr;
					this->rear=nullptr;
				}
				else {
					this->front = this->front->next;
				}
				delete newcustomer;
					this->count--;
			}
			void DETIMECUSCURRENT(string name) {
				if(this->count==1&&this->front->name==name) {
					this->front=nullptr;
					this->rear=nullptr;	
				}
				else {
				    customer* newcustomer = this->front;
					if(newcustomer->name==name) {
						newcustomer=newcustomer->next;
						this->front=newcustomer;
					}
					else{
		
				        while(newcustomer->next->name!=name) {
                            newcustomer=newcustomer->next;
				        }
						if(newcustomer->next->next==nullptr) {
							delete newcustomer;
							this->rear=newcustomer;
							}
						else{
							delete newcustomer->next;
							 newcustomer->next=newcustomer->next->next;	
						    }
					    }
				    }
			}
			customer* xoatimecusoanlinh() {
				customer*newcustomer=this->front;
				while(newcustomer->energy>0) newcustomer=newcustomer->next;
				customer*customerreturn = newcustomer;
				DETIMECUSCURRENT(newcustomer->name);
				this->countoanlinh--;
				this->count--;
				delete newcustomer;
				return customerreturn; 
			}
			customer* xoatimecuschuthuatsu() {
				customer*newcustomer=this->front;
				while(newcustomer->energy<0) newcustomer=newcustomer->next;
				customer*customerreturn = newcustomer;
				DETIMECUSCURRENT(newcustomer->name);
				this->countchuthuatsu--;
				this->count--;
				delete newcustomer;
				return customerreturn;
			}
			void printTIMECUS() {
				customer* p= this->front;
                while(p!=nullptr) {
					p->print();
					p=p->next;
				}
				delete p;
			}
			string GETCUSFRONT() {
				return this->front->name;
				
			}
			int getchuthatsu() {
				return this->countchuthuatsu;
			}
			int getoanlinh() {
				return this->countoanlinh;
			}
			customer* timoanlinhcuoicung() {
				int numoanlinh=this->countoanlinh;
				customer* findoanlinh=this->front;
				while(numoanlinh) {
                     if(findoanlinh->energy<0) numoanlinh--;
					 if(numoanlinh==0) break;
			        findoanlinh=findoanlinh->next;
				}
				return findoanlinh;
			}
			customer*timchuthuatsucuoicung() {
				int numchuthuatsu=this->countchuthuatsu;
				customer* findchuthuatsu= this->front;
				while(numchuthuatsu) {
					if(findchuthuatsu->energy>0) numchuthuatsu--;
					if(numchuthuatsu==0) break;
					findchuthuatsu=findchuthuatsu->next;
				}
				return findchuthuatsu;
			}
			int getcount() {
				return this->count;
			}
			
		};
        customer* X=nullptr;
		QUEUE* cuswait = new QUEUE();
		TIMECUS* timecus = new TIMECUS();
		cusbiduoi* khachbiduoi= new cusbiduoi();
		TIMEQUEUE* timequeue= new TIMEQUEUE();
		int countcustable=0;
		int oanlinhtable=0;
		int chuthuatsutable=0;
        bool checkname(string name) {
			customer* check = X;
			int count=countcustable;
			if (check==nullptr) return 0;
			while(count--) {
				if(name==check->name){
					check=nullptr;
					delete check;
					return 1;
				}
				check=check->next;
			}
			 check=nullptr;
			delete check;
			return 0;
		}
        void themXtheochieudongho(string name, int energy) {
			customer *cus = new customer(name, energy, nullptr,nullptr);
            cus->next=X->next;
					X->next=cus;
					cus->prev=X;
					X=X->next->next;
					X->prev=cus;
					X=cus;
			cus=nullptr;
			delete cus;
		}
		void themXnguocchieudongho(string name, int energy) {
			customer *cus = new customer (name, energy, nullptr, nullptr);
			cus->prev=X->prev;
			    	X->prev=cus;
					cus->next=X;
					X=X->prev->prev;
					X->next=cus;
					X=cus;
			cus=nullptr;
			delete cus;
		}
		void xoaXtheochieudongho() {
			if(countcustable==1) {
				X=nullptr;
				countcustable--;
				return;
			}
			else if(countcustable==2) {
				customer* newcus= X;
				X=X->next;
			    X->next=X->prev=X;
				delete newcus;
				return;
			}
              customer* newcus=X;
					    X->next->prev=X->prev;
						X->prev->next=X->next;
						X=newcus->next;
					    //newcus=nullptr;
					  delete newcus;
            countcustable--;
		}
		void xoaXnguocchieudongho() {
			if(countcustable==1) {
				X=nullptr;
				countcustable--;
				return;
			}
			else if(countcustable==2) {
				customer* newcus= X;
				X=X->next;
			    X->next=X->prev=X;
				delete newcus;
				return;
			}
			customer* newcus=X;
					    X->prev->next=X->next;
					    X->next->prev=X->prev;
					    X=newcus->prev;
						//newcus=nullptr;
						delete newcus;
			countcustable--;
		}       
        void reversalX(customer* customer1, customer* customer2, int n) {
			// customer* Xswap = X->next;
			// X->next=Xswap->next;
			// Xswap->prev=X->prev;
			// X->prev=Xswap;
			// Xswap->next=X;
			// X=X->next;
			// X->prev=Xswap->next;
			// X=X->prev;
			// Xswap=Xswap->prev;
			// Xswap->next=X->prev;
            // Xswap=nullptr; // delete
			// X=X->prev;
            customer1->next=customer2->next;
			customer2->next=customer1;
			customer2->prev=customer1->prev;
			customer1->prev=customer2;
            customer2->prev->next=customer2;
			customer1->next->prev=customer1;
			
		}
		void reversalX(customer* cus1, customer* cus2) {
             customer* nc1=new customer(cus1->name,cus1->energy, cus1->prev, cus1->next);
			cus1->next=cus2->next;
			cus1->prev=cus2->prev;
			cus2->next=nc1->next;
			cus2->prev=nc1->prev;
			cus1->next->prev=cus1->prev->next=cus1;
			cus2->next->prev=cus2->prev->next=cus2;
			delete nc1;
			
		}
		int inssort(int n, int k, int begin) {
			int a=0;
			for(int i=k; i<n; i+=k) {
				for(int j=i; j>=k&&((abs(cuswait->getcustomernumber(j-k+begin)->energy)<abs(cuswait->getcustomernumber(j+begin)->energy))||(abs(cuswait->getcustomernumber(j-k+begin)->energy)==abs(cuswait->getcustomernumber(j+begin)->energy)&&timequeue->checkthutuQUEUE(cuswait->getcustomernumber(j+begin),cuswait->getcustomernumber(j-k+begin)))); j=j-k){
			        cuswait->swapcustomer(cuswait->getcustomernumber(j+begin),cuswait->getcustomernumber(j-k+begin));
					a++;
				}
			}
			return a;
		}
		int shellsort(int n) {
		    int s=0;
			for(int i=n/2; i>2; i/=2) {
			    for(int j=0; j<i; j++) {
				    s+=inssort(n-j, i,j);
				}
			}
			s+=inssort(n,1,0);
			return s;
		}
		void RED(string name, int energy)
		{   
			if(energy==0||checkname(name)||cuswait->checkname(name)||MAXSIZE==0) return;
			customer *cus = new customer (name, energy, nullptr, nullptr);
			if(countcustable<MAXSIZE/2) {
			//cout << name << " " << energy << endl;
                if(X==nullptr) {
					X=cus;
					X->next=X;
					X->prev=X;
				}
			    else if(energy>=X->energy) {
				    themXtheochieudongho(name,energy);
			    }
			    else if(energy<X->energy) {
					themXnguocchieudongho(name,energy);
			    }
	            countcustable++;
				timecus->ENTIMECUS(name,energy);
				if(energy>0) chuthuatsutable++;
			    else oanlinhtable++;
			}
            else if(this->countcustable>=MAXSIZE/2&&this->countcustable<MAXSIZE) {
				if(MAXSIZE==1) {
					X=cus;
					X->next=X;
					X->prev=X;
				}
				else if(MAXSIZE>1) {
				    int res;
					int checkres;
				    int maxres=0;
			    	customer* newX=X;
			    	customer* currentX=X;
					int count = countcustable;
			    	while(count--) {
				    	res=energy-newX->energy;
                        if(maxres<abs(res)) {
				    		maxres=abs(res);
							checkres=res;
				    		currentX=newX;
				    	}
				    	newX=newX->next;
			    	}
					X=currentX;
			    	if(checkres<0) {
				    	themXnguocchieudongho(name,energy);
			    	}
			    	else if (checkres>=0) {
				    	themXtheochieudongho(name,energy);
				    }
				}
				this->countcustable++;
                timecus->ENTIMECUS(name,energy);
				if(energy>0) chuthuatsutable++;
			    else oanlinhtable++;
			}
			else if(this->countcustable>=MAXSIZE&&cuswait->getcountQueue()<MAXSIZE) {
			 	cuswait->EnQueue(name,energy);
				timequeue->EnTIMEQUEUE(name,energy);
			}
			

		}
		void BLUE(int num)
		{
			int count=num;
			while(count&&countcustable){
			    while(X->name!=timecus->GETCUSFRONT()) {
			        X=X->next;
			    }
				if(this->countcustable==1) {
					if(X->energy>0) chuthuatsutable--;
					else oanlinhtable--;
					X=nullptr;
					this->countcustable=0;
					
				}
				else
			    {
                    if(X->energy>0) {
					  chuthuatsutable--;
					  xoaXtheochieudongho();
					}
				    else if(X->energy<0) {
					  oanlinhtable--;
					  xoaXnguocchieudongho();
				    }
				}
		        timecus->DETIMECUS();
				count--;
			}
				while(this->countcustable<MAXSIZE&&cuswait->getcountQueue()) {
					customer* n=new customer(cuswait->getnameQUEUE(),cuswait->getenergyQUEUE(), nullptr,nullptr);
					cuswait->DeQueue();
					RED(n->name, n->energy);
					timequeue->DeTIMEQUEUECURRENT(n->name);

				}
		}
		void PURPLE()
		{
			 if(cuswait->getcountQueue()==0) return;
             int countswap=0;
			 int count = cuswait->getnumberofcustomer(cuswait->getcustomerhaveenergyMax())+1;
			// if(count>1) {
			// 	for(int k=count/2; k>0; k=k/2) {
			//     	for(int i=k; i<count; i++) {
			// 			if (k==2) break;
			// 	    	customer* getcustomer=cuswait->getcustomernumber(i);
			// 	    	customer* temp=new customer(getcustomer->name,getcustomer->energy, nullptr);
			// 	    	int j;
			// 		    for(j=i; j>=k&&((abs(cuswait->getcustomernumber(j-k)->energy)<abs(temp->energy))||(abs(cuswait->getcustomernumber(j-k)->energy)==abs(temp->energy)&&timequeue->checkthutuQUEUE(temp,cuswait->getcustomernumber(j-k)))); j=j-k) {
			// 		    	cuswait->assigncustomer(j,cuswait->getcustomernumber(j-k));
			// 			    countswap++;			
			// 		    }
			// 		    cuswait->assigncustomer(j,temp);
			// 	    }
			//     }
			// }
			//cout<<shellsort(count);;
			  BLUE(shellsort(count)%MAXSIZE);



		}
		void REVERSAL()
		{
			if(countcustable<=2) return;
			int reoanlinh=oanlinhtable/2;
			int rechuthuatsu=chuthuatsutable/2;
			string namecurrent=X->name;
			if(countcustable>2) {
				customer* thuatsukeXnguoc=X;
				customer* thuatsukeXtheo=X->next;
				if(rechuthuatsu) {
				    while(thuatsukeXnguoc->energy<0) thuatsukeXnguoc=thuatsukeXnguoc->prev;
				    while(thuatsukeXtheo->energy<0) thuatsukeXtheo=thuatsukeXtheo->next;
				}
                customer* runX=X->next;
				string namerunXnext;
				string nameXprev;
				if(reoanlinh>0) {
					while(reoanlinh--) {
					    while(runX->energy>0) runX=runX->next;
                        while(X->energy>0) X=X->prev;
				        namerunXnext=runX->next->name;
					    nameXprev = X->prev->name;
                        if(X->next->name==runX->name) reversalX(X,runX,2);
				    	else if(X->prev->name==runX->name) reversalX(runX,X,2);
					    else reversalX(X,runX);
				    	while(X->name!=nameXprev) X=X->prev;
				    	while(runX->name!=namerunXnext) runX=runX->next;
				    }
				}
				while(X->name!=thuatsukeXnguoc->name) X=X->next;
                while(runX->name!=thuatsukeXtheo->name) runX=runX->next;
				if(rechuthuatsu>0) {
					while(rechuthuatsu--) {
					    while(runX->energy<0) runX=runX->next;
					    while(X->energy<0) X=X->prev;
				    	namerunXnext=runX->next->name;
				    	nameXprev=X->prev->name;
				    	if(X->next->name==runX->name) reversalX(X,runX,2);
				    	else if(X->prev->name==runX->name) reversalX(runX,X,2);
				    	else reversalX(X,runX);
				     	while(X->name!=nameXprev) X=X->prev;
				    	while(runX->name!=namerunXnext) runX=runX->next;
				    }
				}
				while(X->name!=namecurrent) X=X->next;
				thuatsukeXnguoc=nullptr;
				thuatsukeXtheo=nullptr;
				runX=nullptr;
				delete thuatsukeXnguoc;
				delete thuatsukeXtheo;
				delete runX;
			}
			
		}
		void UNLIMITED_VOID()
		{
			//cout << "unlimited_void" << endl;
			customer* findX=X;
			customer*printX=X;
		    if (countcustable<4) return;
			else if (countcustable==4) {
				int countfind=3;
				int countprint=4;
				int checkenergyX=findX->energy;
				while (countfind--) {
					if(checkenergyX>=findX->next->energy) {
						printX=findX->next;
						checkenergyX=findX->next->energy;
					}
					findX=findX->next;
				}
				while(countprint--) {
					printX->print();
					printX=printX->next;
				}
			}
			else {
				int sum;
				int minsum=0;
				int number=4;
				int maxlength=4;
				customer*sumX=X;
				customer*Xfind;
				customer* Xluu=X;
				customer*Xreturn=X;
				for(int i=0; i<4; i++) {
					minsum+=sumX->energy;
					sumX=sumX->next;
				}
				
				for(int i=0; i<countcustable; i++) {
					sumX=Xluu;  //gang sumX=X;
					Xluu=Xluu->next;
					sum=0;
                    for(int j=0; j<countcustable; j++) {
                        sum+=sumX->energy;
						sumX=sumX->next;
						if(j>=3&&(minsum>sum||(minsum==sum&&maxlength<=(j+1)))) {
							minsum=sum;
							Xreturn=Xluu->prev;
							number=j+1;
							maxlength=j+1;
						}
					}
				}
                customer*Xmininarr=Xreturn;
				customer*Xhead=Xreturn;
		        int Xmin=Xreturn->energy;
				int savenumber=0;
				for(int i=0; i<number-1; i++) {
					if(Xmin>Xreturn->next->energy) {
                        Xmin=Xreturn->next->energy;
						Xmininarr=Xreturn->next;
						savenumber=i+1;
					}
					Xreturn=Xreturn->next;
				}
				number=number-savenumber;
				while(number--) {
                    Xmininarr->print();
					Xmininarr=Xmininarr->next;
				}
				while(savenumber--) {
					Xhead->print();
					Xhead=Xhead->next;
				}
				sumX=nullptr;
				Xfind=nullptr;
				Xluu=nullptr;
	            Xhead=nullptr;
				Xreturn=nullptr;
				delete sumX;
				delete Xfind;
				delete Xluu;
				delete Xhead;
				delete Xreturn;
			}
			findX=nullptr;
			printX=nullptr;
			delete findX;
			delete printX;
		}
		void DOMAIN_EXPANSION()
		{
			//cout << "domain_expansion" << endl;
			cout<<"DOMAIN_EXPANSION "<<"line "<<line<<endl;
			if(oanlinhtable==0&&cuswait->getcountoanlinh()==0||chuthuatsutable==0&&cuswait->getcountthuatsu()==0) return;
            int energypos=0;
			int energyneg=0;
			int counttalbe=countcustable;
			if(cuswait->getcountQueue()) {
			energypos+=cuswait->getenergypositive();
			energyneg+=cuswait->getenergynegative();
			}
			customer* newX=X;
			while(counttalbe--) {
				if(newX->energy>0) energypos+=newX->energy;
				else energyneg+=newX->energy;
				newX=newX->next;
			}
			newX=nullptr;
			delete newX;
			if(energypos>=abs(energyneg+energypos)) {
				if(oanlinhtable) {
				customer* oanlinhcuoicung = timecus->timoanlinhcuoicung();
                customer* Xcuoi=X;
				while(Xcuoi->name!=oanlinhcuoicung->name) Xcuoi=Xcuoi->next;
				//delete oanlinhcuoicung;
				while(Xcuoi->energy<0) Xcuoi=Xcuoi->prev; // chu thuat su ke oan linh cuoi cung nguoc chieu kim dong ho
				while(oanlinhtable) {
					while(X->energy>0) X=X->next;
					xoaXnguocchieudongho();
					oanlinhtable--;
				}
				while(timecus->getoanlinh()) {
					customer* p = timecus->xoatimecusoanlinh();
					khachbiduoi->pushcus(p->name,p->energy);
				}
                 while(X->name!=Xcuoi->name) X=X->next;
				 }
				if(cuswait->getcountQueue()) {
                    while(timequeue->getoanlinhtrongqueue()) {
				    	customer* px = timequeue->XoaOanLinh();
						cuswait->DeQueueCURRENT(px->name);
				    	khachbiduoi->pushcus(px->name,px->energy);
			    	}
				}
			}
			else {
                if(chuthuatsutable) {
				customer* chuthuatsucuoicung = timecus->timchuthuatsucuoicung();
                customer* Xcuoi=X;
				while(Xcuoi->name!=chuthuatsucuoicung->name) Xcuoi=Xcuoi->next;
				//delete chuthuatsucuoicung;
				while(Xcuoi->energy>0) Xcuoi=Xcuoi->next; // tim oan linh gan nhat theo chieu kim dong ho

				 while(chuthuatsutable) {
					while(X->energy<0) X=X->next;
				 	xoaXtheochieudongho();
				    chuthuatsutable--;
				}
				while(timecus->getchuthatsu()) {
					customer* pduoi = timecus->xoatimecuschuthuatsu();
					khachbiduoi->pushcus(pduoi->name,pduoi->energy);
				}
				while(X->name!=Xcuoi->name) X=X->next;
				}
				if(cuswait->getcountQueue()) {
                    while(timequeue->getchuthuatsutrongqueue()) {
				    	customer* px = timequeue->XoaChuThuatSu();
						cuswait->DeQueueCURRENT(px->name);
				    	khachbiduoi->pushcus(px->name,px->energy);
			    	}
				}
				
			}
			while(countcustable<MAXSIZE&&cuswait->getcountQueue()) {
				customer* n = new customer(cuswait->getnameQUEUE(), cuswait->getenergyQUEUE(), nullptr,nullptr);
				cuswait->DeQueue();
				timequeue->DeTIMEQUEUECURRENT(n->name);
				RED(n->name,n->energy);
			}
            khachbiduoi->printcus();
			khachbiduoi->~cusbiduoi();
		}
		void LIGHT(int num)
		{
			cout<<"LIGHT "<<num<<" line "<<line<<endl;
			int count=countcustable;
			customer* printcus=X;
			if(num==0&&cuswait->getcountQueue()) {
				cuswait->printQUEUE();
			}
			else if(num>0&&countcustable) {	
	    		while(count--) {
				    printcus->print();
					printcus=printcus->next;
			    }
			}
			else if(num<0&&countcustable) {
                while(count--){
					printcus->print();
					printcus=printcus->prev;
				}
			}
		}
};