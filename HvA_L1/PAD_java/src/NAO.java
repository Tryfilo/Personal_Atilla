import com.aldebaran.qi.Application;
import com.aldebaran.qi.helper.proxies.*;

public class NAO {
    public static Application application;

    // Here is the method of connecting to the robot.
    public void connect(String hostname, int port) {
        String robotUrl = "tcp://" + hostname + ":" + port;
        // Create a new application
        application = new Application(new String[]{}, robotUrl);
        // Start your application
        application.start();
    }

    // Here is the method of setting up the posture
    public void postureSetUp(String posture) throws Exception {
        ALRobotPosture robotPosture = new ALRobotPosture(NAO.application.session());
        robotPosture.goToPosture(posture, 0.7f);
    }

    // Here is the method of opening the hands
    public void openHand(String handName) throws Exception {
        ALMotion robotMotion = new ALMotion(application.session());
        robotMotion.openHand(handName);
    }

    // Here is the method of closing the hands
    public void closeHand(String handName) throws Exception {
        ALMotion robotMotion = new ALMotion(application.session());
        robotMotion.closeHand(handName);
    }

    // Here is the method for the robot to talk
    public void speak(String text) throws Exception {
        // Create an ALTextToSpeech object and link it to your current session
        ALTextToSpeech tts = new ALTextToSpeech(application.session());
        // Make your robot say something
        tts.say(text);
    }

    // Here is the method where the robot their speaking language gets set
    public void setLanguage(String language) throws Exception {
        ALTextToSpeech tts = new ALTextToSpeech(application.session());
        tts.setLanguage(language);
    }
}