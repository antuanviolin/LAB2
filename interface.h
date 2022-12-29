#ifndef LAB2_INTERFACE_H
#define LAB2_INTERFACE_H

namespace interface {
    class interfaceException : public std::exception {
    public:
        explicit interfaceException(std::string error) : error_(std::move(error)) {}

        const char *what() const noexcept override { return error_.c_str(); }

    private:
        std::string error_;
    };


    class interface {
    public:
        virtual bool toHhandle(int) = 0;

        virtual void handel(char **) = 0;
    };

    class onlineInterface : public interface {
    public:
        bool toHhandle(int argc) override;

        void handel(char *argv[]) override;
    };

    class onlineInterfaceWithoutInputFile : public interface {
    public:
        bool toHhandle(int argc) override;

        void handel(char *argv[]) override;
    };

    class offlineInterfaceV1 : public interface {
        bool toHhandle(int argc) override;

        void handel(char *argv[]) override;
    };

    class offlineInterfaceV2 : public interface {
        bool toHhandle(int argc) override;

        void handel(char *argv[]) override;
    };
}
#endif //LAB2_INTERFACE_H
