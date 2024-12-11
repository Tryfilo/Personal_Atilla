import com.aldebaran.qi.helper.proxies.ALMotion;

public class NAO_hug {
    private NAO nao;

    public NAO_hug(NAO nao) {
        this.nao = nao;
    }

    public void hug() throws Exception {
        ALMotion robotMotion = new ALMotion(NAO.application.session());
        robotMotion.setStiffnesses("LArm", 1.0); // this is where the stiffness get changed to make the left arm movable
        robotMotion.setStiffnesses("RArm", 1.0); // this is where the stiffness get changed to make the right arm movable
        nao.postureSetUp("Stand"); // this is to let the robot stand before giving a high five
        nao.setLanguage("Dutch"); // this changes the language the robot is speaking in so the sentence "high five" is pronounced the right way
        System.out.println("Hug"); // this is a check
        this.nao.speak("Knuffel"); // this is as a warning to not accidentally scare the elderly people
        double lShoulderPitchAngles = Math.toRadians(-30); // this is where the angles get set for the left parts
        double rShoulderPitchAngles = Math.toRadians(-30); // this is where the angles get set for the right parts
        double lShoulderRollAngles = Math.toRadians(30);
        double rShoulderRollAngles = Math.toRadians(-30);
        double lElbowYawAngles = Math.toRadians(-50);
        double rElbowYawAngles = Math.toRadians(50);
        double lElbowRollAngles = Math.toRadians(-20);
        double rElbowRollAngles = Math.toRadians(20);
        robotMotion.setAngles("LShoulderPitch", lShoulderPitchAngles, 0.2f); // this is where the shoulder turns upward
        robotMotion.setAngles("RShoulderPitch", rShoulderPitchAngles, 0.2f);
        robotMotion.setAngles("LShoulderRoll", lShoulderRollAngles, 0.2f); // this is where the shoulder starts turning away from the body
        robotMotion.setAngles("RShoulderRoll", rShoulderRollAngles, 0.2f);
        robotMotion.setAngles("LElbowYaw", lElbowYawAngles, 0.2f); // this is where the elbow starts rotating
        robotMotion.setAngles("RElbowYaw", rElbowYawAngles, 0.2f);
        robotMotion.setAngles("LElbowRoll", lElbowRollAngles, 0.2f); // this is where the elbow starts turning
        robotMotion.setAngles("RElbowRoll", rElbowRollAngles, 0.2f);
        this.nao.openHand("LHand"); // this is to open the hand to show that the robot can receive a hug
        this.nao.openHand("RHand");
        Thread.sleep(6000); // this is a time period where the person on the receiving end has the time to give the high five
        nao.speak("Mijn armen gaan omlaag");
        Thread.sleep(3000);
        this.nao.closeHand("LHand"); // this is to close the hand
        this.nao.closeHand("RHand");
        lShoulderPitchAngles = Math.toRadians(65); // this is where the angles get set back for the left parts
        rShoulderPitchAngles = Math.toRadians(65); // this is where the angles get set back for the right parts
        lShoulderRollAngles = Math.toRadians(18);
        rShoulderRollAngles = Math.toRadians(-18);
        lElbowYawAngles = Math.toRadians(-80);
        rElbowYawAngles = Math.toRadians(80);
        lElbowRollAngles = Math.toRadians(0);
        rElbowRollAngles = Math.toRadians(0);
        robotMotion.setAngles("LShoulderPitch", lShoulderPitchAngles, 0.1f); // this is where the shoulder gets set back downward
        robotMotion.setAngles("RShoulderPitch", rShoulderPitchAngles, 0.1f);
        robotMotion.setAngles("LShoulderRoll", lShoulderRollAngles, 0.1f); // this is where the shoulder gets back closer to the body
        robotMotion.setAngles("RShoulderRoll", rShoulderRollAngles, 0.1f);
        robotMotion.setAngles("LElbowYaw", lElbowYawAngles, 0.1f); // this is where the elbow starts rotating back
        robotMotion.setAngles("RElbowYaw", rElbowYawAngles, 0.1f);
        robotMotion.setAngles("LElbowRoll", lElbowRollAngles, 0.1f); // this is were the elbow starts turning back
        robotMotion.setAngles("RElbowRoll", rElbowRollAngles, 0.1f);
        Thread.sleep(500);
        robotMotion.setStiffnesses("LArm", 1.0); // this is where the arms get back in the proper place
        robotMotion.setStiffnesses("RArm", 1.0);
    }
}
