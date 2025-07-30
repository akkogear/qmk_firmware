typedef union {
    uint32_t raw;
    struct {
        uint8_t flag : 1;
        uint8_t devs : 3;
        uint8_t rgb_color : 4;

        uint8_t record_last_mode;

        uint8_t last_btdevs : 3;
        uint8_t dir_flag : 1;
        uint8_t rgb_enable : 1; 
        uint8_t sleep_timeout : 3;
        
        uint8_t moude : 4;
        uint8_t ctrl_app_flag : 1;
        uint8_t rgb_tog_filp : 1; 
    };
} confinfo_t;

confinfo_t confinfo;
