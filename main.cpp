#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int max_users = 1000;

int main() {
	string enter_name, name[max_users] = { "Sadeed" };
	int enter_cnic, cnic[max_users] = { 123 };
	int enter_accnum, accnum, account_number[max_users] = { 111 };
	int access, enter_pin, pin[max_users] = { 9999 };
	long int withdraw, deposit, savings[max_users] = { 1200 }, defaults[max_users] = { 500 }, current[max_users] = { 1500 };
	int option;
	int userindex = -1;
	
	start:
		cout<<"1 Account Detail \n2 Open an Account \n3 Close an Account \n4 Show Balance \n5 Deposit Amount \n6 Withdraw Amount \n7 Exit \nSelect Option: ";
		cin>>option;
	cout<<endl;
	
	switch(option)
	{
		case 1:
			start1:
				userindex = -1;
				cout<<"Enter your CNIC Number: ";
				cin>>enter_cnic;
			
			for( int i=0; i < max_users; i++ )
			{
				if ( enter_cnic == cnic[i] )
				{
					userindex = i;
					break;
				}				
			}
			
			if ( userindex != -1 )
			{
				cout<<"Account found!"<<endl<<"Details:"<<endl;
				cout<<"Acount Owner: "<<name[userindex]<<endl;
				cout<<"Account Number: "<<account_number[userindex]<<endl;
				cout<<"Account Pin: "<<pin[userindex]<<endl<<endl;
				goto start;
			}			
			else
			{
				cout<<"No Record Found!"<<endl<<endl;
				nav1:
					cout<<"1 Back \n2 Main Menu \n3 Exit \nSelect Option: ";
					cin>>option;
				switch(option)
				{
					case 1:
						cout<<endl;
						goto start1;
						break;
					case 2:
						cout<<endl;
						goto start;
						break;
					case 3:
						cout<<"Exiting System!";
						return 0;
						break;
					default:
						cout<<"Invalid Selection!"<<endl;;
						goto nav1;
						break;
				}
			}
			break;
			
		case 2:
			start2:
				userindex = -1;
				nam:				
					getline(cin, enter_name);
			    if (enter_name.empty())
				{
			        cout<<"Enter your name: ";
			        goto nam;
			    }
				cout<<"Enter your CNIC number (3 digits): ";
				cin>>enter_cnic;
				
			for( int i=0; i < max_users; i++ )
			{
				if ( enter_cnic == cnic[i] )
				{
					userindex = i;
					break;
				}
			}
			if (userindex != -1)
			{
				cout<<"An account is already registered to this CNIC!";
				
				nav2:
					cout<<"\n\n1 Back \n2 Main Menu \n3 Exit \nSelect Option: ";
					cin>>option;
				switch(option)
				{
					case 1:
						cout<<endl;
						goto start2;
						break;
					case 2:
						cout<<endl;
						goto start;
						break;
					case 3:
						cout<<"Exiting System!";
						return 0;
						break;
					default:
						cout<<"Invalid Selection!"<<endl;;
						goto nav2;
						break;
				}
				
			}
			else
			{
				for( int i=0; i < max_users; i++ )
				{
					if( cnic[i] == 0 )
					{
						
						name[i] = enter_name;
						cnic[i] = enter_cnic;
						
						again:
							srand(time(0));
						    accnum = rand() % 1000 + 100;
							for( int j=0; j < max_users; j++ )
							{
								if( accnum == account_number[j] )
								goto again;
							}
						
						account_number[i] = accnum;
						
						create:
							cout<<"Create a 4 digit pin: ";
							cin>>enter_pin;
						if (enter_pin > 999 && enter_pin < 10000 )
						{
							cout<<"Pin created!";
							pin[i] = enter_pin;
							cout<<endl<<endl;
							goto start;
						}
						else
						{
							cout<<"Please enter a 4 digit pin!"<<endl<<endl;
							goto create;
						}
						break;
					}
				}
			}
			break;
			
		case 3:
			start3:
				userindex = -1;
				cout<<"Enter Your Account Number: ";
				cin>>enter_accnum;
			
			for( int i=0; i < max_users; i++ )
			{
				if( enter_accnum == account_number[i] )
				{
					userindex = i;
					break;
				}
			}
			
			if( userindex != -1 )
			{
				char sure;
				confirm:
					cout<<"Are you sure you want to delete your account?(y/n): ";
					cin>>sure;
				if( sure == 'y' || sure == 'Y' )
				{
					name[userindex] = "";
					cnic[userindex] = 0;
					account_number[userindex] = 0;
					pin[userindex] = 0;
					cout<<"Account Deleted!"<<endl<<endl;
					goto start;
				}
				else if( sure == 'n' || sure == 'N' )
				{
					cout<<"Account Not Deleted!"<<endl<<endl;
					goto start;
				}
				else
				{
					cout<<"Invalid Option!"<<endl;
					goto confirm;
				}
				
			}
			else
			{
				cout<<"No Account Found!";
				
				nav3:
					cout<<"\n\n1 Back \n2 Main Menu \n3 Exit \nSelect Option: ";
					cin>>option;
									
				switch(option)
				{
					case 1:
						cout<<endl;
						goto start3;
						break;
					case 2:
						cout<<endl;
						goto start;
						break;
					case 3:
						cout<<"Exiting System!";
						return 0;
						break;
					default:
						cout<<"Invalid Selection!"<<endl;;
						goto nav3;
						break;
				}
				
			}
			break;
			
		case 4:
			start4:
				userindex = -1;
				cout<<"Enter Account Number: ";
				cin>>enter_accnum;
				
			for( int i=0; i < max_users; i++ )
			{
				if ( enter_accnum == account_number[i] )
				{
					userindex = i;
					break;
				}
			}
			if ( userindex != -1 )
			{
				retry1:
					cout<<"Enter Account Pin: ";
					cin>>enter_pin;
					
				if( enter_pin == pin[userindex] )
				{
					sub_start4:
						cout<<"1 Current \n2 Default \n3 Savnigs \nSelect Account: ";
						cin>>access;
					
					switch(access)
					{
						case 1:
							cout<<"Current Account Balance: "<<current[userindex];
							break;
						case 2:
							cout<<"Default Account Balance: "<<defaults[userindex];
							break;
						case 3:
							cout<<"Savings Account Balance: "<<savings[userindex];
							break;
						default:
							cout<<"Invalid Selection!";
					}
					
					nav4_1:
						cout<<"\n\n1 Back \n2 Main Menu \n3 Exit \nSelect Option: ";
						cin>>option;
					
					switch(option)
					{
						case 1:
							cout<<endl;
							goto sub_start4;
							break;
						case 2:
							cout<<endl;
							goto start;
							break;
						case 3:
							cout<<"Exiting System!";
							return 0;
							break;
						default:
							cout<<"Invalid Selection!"<<endl;;
							goto nav4_1;
							break;
					}
				}
				else
				{
					cout<<"Invalid Pin!"<<endl<<endl;
					goto retry1;
				}
			}			
			else
			{
				cout<<"No Account Found!"<<endl<<endl;
				
				nav4_2:
						cout<<"1 Back \n2 Main Menu \n3 Exit \nSelect Option: ";
						cin>>option;
					
					switch(option)
					{
						case 1:
							cout<<endl;
							goto start4;
							break;
						case 2:
							cout<<endl;
							goto start;
							break;
						case 3:
							cout<<"Exiting System!";
							return 0;
							break;
						default:
							cout<<"Invalid Selection!"<<endl;;
							goto nav4_2;
							break;
					}
			}
			break;
			
		case 5:
			start5:
				userindex = -1;
				cout<<"Enter Account Number: ";
				cin>>enter_accnum;
			for( int i=0; i < max_users; i++ )
			{
				if ( enter_accnum == account_number[i] )
				{
					userindex = i;
					break;
				}
			}
			if ( userindex != -1 )
			{
				retry2:
					cout<<"Enter Account Pin: ";
					cin>>enter_pin;
				
				if( enter_pin == pin[userindex] )
				{
					sub_start5:
						cout<<"1 Current \n2 Default \n3 Savnigs \nSelect Account In Which You Want To Deposit Amount: ";
						cin>>access;
						cout<<"Enter Amount That You Want To Deposit: ";
						cin>>deposit;
					
					switch(access)
					{
						case 1:
							current[userindex] += deposit;
							cout<<"Current Account Balance: "<<current[userindex];
							break;
						case 2:
							defaults[userindex] += deposit;
							cout<<"Default Account Balance: "<<defaults[userindex];
							break;
						case 3:
							savings[userindex] += deposit;
							cout<<"Savings Account Balance: "<<savings[userindex];
							break;
						default:
							cout<<"Invalid Selection!";
					}
					
					nav5_1:
						cout<<"\n\n1 Back \n2 Main Menu \n3 Exit \nSelect Option: ";
						cin>>option;
					
					switch(option)
					{
						case 1:
							cout<<endl;
							goto sub_start5;
							break;
						case 2:
							cout<<endl;
							goto start;
							break;
						case 3:
							cout<<"Exiting System!";
							return 0;
							break;
						default:
							cout<<"Invalid Selection!"<<endl;;
							goto nav5_1;
							break;
					}
				}
				else
				{
					cout<<"Invalid Pin!"<<endl<<endl;
					goto retry2;
				}
			}
			else
			{
				cout<<"No Account Found!"<<endl<<endl;
				nav5_2:
						cout<<"1 Back \n2 Main Menu \n3 Exit \nSelect Option: ";
						cin>>option;
					
					switch(option)
					{
						case 1:
							cout<<endl;
							goto start5;
							break;
						case 2:
							cout<<endl;
							goto start;
							break;
						case 3:
							cout<<"Exiting System!";
							return 0;
							break;
						default:
							cout<<"Invalid Selection!"<<endl;;
							goto nav5_2;
							break;
					}		
			}
			break;
			
		case 6:
			start6:
			userindex = -1;
			cout<<"Enter Account Number: ";
			cin>>enter_accnum;
			for( int i=0; i < max_users; i++ )
			{
				if ( enter_accnum == account_number[i] )
				{
					userindex = i;
					break;
				}
			}
			if ( userindex != -1 )
			{
				retry3:
					cout<<"Enter Account Pin: ";
					cin>>enter_pin;
				
				if( enter_pin == pin[userindex] )
				{
					sub_start6:
						cout<<"1 Current \n2 Default \n3 Savnigs \nSelect Account From Which You Want To Withdraw Amount: ";
						cin>>access;
						cout<<"Enter Amount That You Want To Withdraw: ";
						cin>>withdraw;
					
					switch(access)
					{
						case 1:
							if( withdraw > current[userindex] )
							{
								cout<<"Insufficient Balance!";
							}
							else
							{
								current[userindex] -= withdraw;
								cout<<"Current Account Balance: "<<current[userindex];
							}
							break;
						case 2:
							if( withdraw > defaults[userindex] )
							{
								cout<<"Insufficient Balance!";
							}
							else
							{
								defaults[userindex] -= withdraw;
								cout<<"Default Account Balance: "<<defaults[userindex];
							}
							break;
						case 3:
							if( withdraw > savings[userindex] )
							{
								cout<<"Insufficient Balance!";
							}
							else
							{
								savings[userindex] -= withdraw;
								cout<<"Savings Account Balance: "<<savings[userindex];
							}
							break;
						default:
							cout<<"Invalid Selection!";
					}
					
					nav6_1:
						cout<<"\n\n1 Back \n2 Main Menu \n3 Exit \nSelect Option: ";
						cin>>option;
					
					switch(option)
					{
						case 1:
							cout<<endl;
							goto sub_start6;
							break;
						case 2:
							cout<<endl;
							goto start;
							break;
						case 3:
							cout<<"Exiting System!";
							return 0;
							break;
						default:
							cout<<"Invalid Selection!"<<endl;;
							goto nav6_1;
							break;
					}
				}
				else
				{
					cout<<"Invalid Pin!"<<endl<<endl;
					goto retry3;				
				}
			}
			else
			{
				cout<<"No Account Found!"<<endl<<endl;
				nav6_2:
						cout<<"1 Back \n2 Main Menu \n3 Exit \nSelect Option: ";
						cin>>option;
					
					switch(option)
					{
						case 1:
							cout<<endl;
							goto start6;
							break;
						case 2:
							cout<<endl;
							goto start;
							break;
						case 3:
							cout<<"Exiting System!";
							return 0;
							break;
						default:
							cout<<"Invalid Selection!"<<endl;;
							goto nav6_2;
							break;
					}		
			}
			break;
			
		case 7:
			cout<<"Exiting System!";
			break;
			
		default:
			cout<<"Invalid Selection!"<<endl<<endl;
			goto start;
	}
	
	return 0;
}
