#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {
    char audio1FilePath[] = "C:\\Users\\user\\Desktop\\c_cause_work\\org.wav";
    // Replace with your voice recording file path
    char audio2FilePath[] = "C:\\Users\\user\\Desktop\\c_cause_work\\morning.wav";
    char audio3FilePath[] = "C:\\Users\\user\\Desktop\\c_cause_work\\night.wav";
    int alarmHour, alarmMinute;

    printf("Enter the alarm time (HH:MM): ");
    scanf("%d:%d", &alarmHour,&alarmMinute);

    while (1) {
        time_t now = time(NULL);
        struct tm *localTime = localtime(&now);

        int currentHour = localTime->tm_hour;
        int currentMinute = localTime->tm_min;

        if (currentHour == alarmHour && currentMinute == alarmMinute) {
           if(alarmHour<=10 && alarmHour>=0){
             // Play the voice recording using the system's default media player
             char command2[256];
             snprintf(command2, sizeof(command2), "start wmplayer.exe \"%s\"", audio2FilePath);
             system(command2);
           }
           else
             if (alarmHour>10 && alarmHour<=19){
              char command1[256];
              snprintf(command1, sizeof(command1), "start wmplayer.exe \"%s\"", audio1FilePath);
              system(command1);
            }
           else {
             char command3[256];
             snprintf(command3, sizeof(command3), "start wmplayer.exe \"%s\"", audio3FilePath);
             system(command3);
            }
            break; // Exit the loop after playing the audio
        }

        // Wait for a short duration before checking the alarm time again
        // To avoid unnecessary CPU usage, we use the sleep() function.
        // In a more advanced application, you might use system-specific timers.
        Sleep(1000);
    }

    return 0;
}
