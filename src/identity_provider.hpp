#ifndef OPEN_BUS_COGNITO_IDENTITY_HPP
#define OPEN_BUS_COGNITO_IDENTITY_HPP

#include <string>
#include <memory>

#include "identity.hpp"
#include "authentication.hpp"

namespace OpenBus {

class IDProvider {
public:
    IDProvider(const IDSettings &idSettings);

    ~IDProvider();

    void signUpUser() const;
    void verifyUser(const std::string & confirmationCode) const;
    void resendCode() const;

    AuthenticationResult passwordAuthenticate() const;

    void deleteUser(const AuthenticationResult & authentication) const;

private:
    IDSettings settings;

    struct IDProviderClient;
    std::unique_ptr<IDProviderClient> idProviderClient;
};
    

} // namespace OpenBus

#endif // OPEN_BUS_COGNITO_IDENTITY_HPP
