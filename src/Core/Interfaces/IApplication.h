#ifndef APPLICATION_INTERFACE_H
#define APPLICATION_INTERFACE_H

class IApplication
{
protected:

    IApplication() = default;
    virtual ~IApplication() = default;

    virtual bool Initialize() = 0;
    virtual bool StartUp() = 0;
    virtual bool ShutDown() = 0;
};

#endif