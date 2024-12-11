import com.aldebaran.qi.Application;
import com.aldebaran.qi.helper.proxies.ALRobotPosture;

public class NAO_lying {

    private Application application;

    public void lyingBelly() throws Exception {
        ALRobotPosture robotPosture = new ALRobotPosture(this.application.session());
        robotPosture.goToPosture("LyingBelly", 0.5f);
    }

    public void lyingBack() throws Exception {
        ALRobotPosture robotPosture = new ALRobotPosture(this.application.session());
        robotPosture.goToPosture("LyingBack", 0.5f);
    }
}
