#ifndef PARTICIPANT_H
#define PARTICIPANT_H

enum Limba {romana , franceza , germana , engleza};

class Participant
{
    public:
        Participant();
        virtual Limba Vorbeste();
        virtual ~Participant();

    protected:

    private:
};

#endif // PARTICIPANT_H
