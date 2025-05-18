#ifndef CANDIDATE_H
#define CANDIDATE_H

#include "user.h"

class Candidate: public User
{
public:
    Candidate(QString &name, QString &surname, QString &id, QString &location, QString &role, QString &email, QString &password);
};

#endif // CANDIDATE_H
