#include "appfs.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"

// Constants
static char const TAG[] = "main";

void app_main(void) {
    while (1) {
        ESP_LOGI(TAG, "Application has started succesfully.");

        bool           valid    = false;
        const char*    argument = NULL;
        appfs_handle_t handle   = appfsBootselGet(&valid, &argument);

        if (handle == APPFS_INVALID_FD) {
            ESP_LOGE(TAG, "Application not started from AppFS");
        } else {
            ESP_LOGI(TAG, "Application started from AppFS");
        }

        if (valid) {
            ESP_LOGW(TAG, "Application started without an argument provided");
        } else {
            ESP_LOGI(TAG, "Argument: %s", argument);
        }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
