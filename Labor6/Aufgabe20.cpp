
#include <string>
#include <iostream>
using namespace std;


// Implementierung
class AuthenticationResult 
{
protected:
    bool authenticated;
    string username = "unauthenticated_user";
public:
    AuthenticationResult(bool _authenticated, string _username) 
    {
        authenticated = _authenticated;
        username = _username;
    }
    string getUser() 
    {
        return username;
    }
    bool getAuth() 
    {
        return authenticated;
    }
};

class IAuthentification 
{
public:
    virtual AuthenticationResult authenticate() 
    {
        return AuthenticationResult(false, "unauthenticated_user");
    }
};

class MockAuth : public IAuthentification 
{
public:
    AuthenticationResult authenticate() override 
    {
        return AuthenticationResult(true, "Default");
    }
};

class UsernamePassword : public IAuthentification 
{
public:
    AuthenticationResult authenticate() override 
    {
        string user;
        string passwort;
        cout << "Username:" << endl;
        cin >>  user;
        cout << "Password:" << endl;
        cin >> passwort;
        if (user == passwort)
        {
            return AuthenticationResult(true, user);
        }
        return AuthenticationResult(false, user);
    }
};

class Certificate : public IAuthentification 
{
public:
    AuthenticationResult authenticate() override 
    {
        string zert;
        cout << "Zertifikatsaussteller:" << endl;
        cin >> zert;
        if (zert == "hs-esslingen")
        {
            return AuthenticationResult(true, "certificate.owner");
        }
        return AuthenticationResult(false, "certificate.owner");
    }
};


class Client 
{
public:
    IAuthentification* auth;
    void setAuthentication(IAuthentification* _auth) 
    {
        auth = _auth;
    }
    void execute() {
        AuthenticationResult authentication = auth->authenticate();
        if (authentication.getAuth())
        {
            cout << "Das Programm wird ausgefuhrt fur " << authentication.getUser() << "." << endl;
        }
        else
        {
            cout << "Das Programm konnte nicht ausgefuhrt werden." << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    Client client;

    cout << "Authentifizierung uber MockAuth" << endl;
    IAuthentification* mockauth = new MockAuth();
    client.setAuthentication(mockauth);
    client.execute();

    cout << "Authentifizierung uber UsernamePassword" << endl;
    IAuthentification* usernamepassword = new UsernamePassword();
    client.setAuthentication(usernamepassword);
    client.execute();

    cout << "Authentifizierung uber Zertifikat" << endl;
    IAuthentification* certificate = new Certificate();
    client.setAuthentication(certificate);
    client.execute();
    return 0;
}