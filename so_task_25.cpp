#include <iostream>
#include <memory>


class DisplayDrv {
public:
    virtual void wykonaj() = 0;
    virtual ~DisplayDrv()
    {
        std::cout << "Deletin DisplayDrv" << std::endl;
    }
};

class LowResDisplayDrv : public DisplayDrv {
public:
    void wykonaj() override
    {
        std::cout << "LowResDisplayDrv" << std::endl;
    }
};

class HighResDisplayDrv : public DisplayDrv {
public:
    void wykonaj() override
    {
        std::cout << "HighResDisplayDrv" << std::endl;
    }
};

class PrinterDrv {
public:
    virtual void wykonaj() = 0;
    virtual ~PrinterDrv()
    {
        std::cout << "Deleting PrinterDrv" << std::endl;
    }
};

class LowResPrinterDrv : public PrinterDrv {

public:
    void wykonaj() override
    {
        std::cout << "LowResPrinterDrv" << std::endl;
    }
};

class HighResPrinterDrv : public PrinterDrv {
public:
    void wykonaj() override
    {
        std::cout << "HighResPrinterDrv" << std::endl;
    }
};

class AbstractResFactory {
public:
    virtual std::unique_ptr<DisplayDrv> getDispDrv() = 0;
    virtual std::unique_ptr<PrinterDrv> getPrintDrv() = 0;
};

class LowResFactory : public AbstractResFactory {
public:
    std::unique_ptr<DisplayDrv> getDispDrv() override
    {
        std::unique_ptr<DisplayDrv> p(new LowResDisplayDrv);
        return p;
    }
    std::unique_ptr<PrinterDrv> getPrintDrv() override
    {
        std::unique_ptr<PrinterDrv> p(new LowResPrinterDrv);
        return p;
    }
};

class HighResFactory : public AbstractResFactory {
public:
    std::unique_ptr<DisplayDrv> getDispDrv() override
    {
        std::unique_ptr<DisplayDrv> p(new HighResDisplayDrv);
        return p;
    }
    std::unique_ptr<PrinterDrv> getPrintDrv() override
    {
        std::unique_ptr<PrinterDrv> p(new HighResPrinterDrv);
        return p;
    }
};

auto main() -> int
{
    std::unique_ptr<AbstractResFactory> fabryka(new LowResFactory);
    std::unique_ptr<DisplayDrv> ddrv = fabryka->getDispDrv();
    std::unique_ptr<PrinterDrv> pdrv = fabryka->getPrintDrv();
    ddrv->wykonaj();
    pdrv->wykonaj();

    std::cout << std::endl;

    fabryka = std::make_unique<HighResFactory>();
    ddrv = fabryka->getDispDrv();
    pdrv = fabryka->getPrintDrv();

    std::cout << std::endl;

    ddrv->wykonaj();
    pdrv->wykonaj();

    std::cout << std::endl;
}