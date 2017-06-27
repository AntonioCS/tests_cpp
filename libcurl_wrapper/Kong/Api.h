#ifndef API_H
#define API_H

namespace KongAPI {

    class Api {
    public:
        Api();
        Api(const Api& orig);
        virtual ~Api();

        //POST
        bool add(std::string name, std::string request_host, std::string request_path,
                std::string upstream_url, bool strip_request_path = false, bool preserv_host = false);

//        //GET
//        void list();
//        
//        //GET
//        void get(std::string name_id);
        
        
    private:

    };

}
#endif /* API_H */

