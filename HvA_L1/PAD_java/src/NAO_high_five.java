import com.aldebaran.qi.helper.proxies.ALMotion;

public class NAO_high_five {
    private NAO nao;

    public NAO_high_five(NAO nao) {
        this.nao = nao;
    }

    // this method is to let the NAO give a high five
    public void highFive() throws Exception {
        ALMotion robotMotion = new ALMotion(NAO.application.session());
        robotMotion.setStiffnesses("LArm", 1.0); // this is where the stiffness get changed to make the arm movable
        nao.postureSetUp("Stand"); // this is to let the robot stand before giving a high five
        System.out.println("HighFive"); // this is a check
        nao.setLanguage("English"); // this changes the language the robot is speaking in so the sentence "high five" is pronounced the right way
        nao.speak("High Five"); // this is as a warning to not accidentally scare the elderly people
        double anglesShoulderPitch = Math.toRadians(-30); // this is where the angles get set
        double anglesShoulderRoll = Math.toRadians(20);
        double anglesElbowYaw = Math.toRadians(-50);
        double anglesElbowRoll = Math.toRadians(-20);
        robotMotion.setAngles("LShoulderPitch", anglesShoulderPitch, 0.3f); // this is where the shoulder starts moving upwards
        robotMotion.setAngles("LShoulderRoll", anglesShoulderRoll, 0.3f); // this is where the shoulder starts turning away from the body
        robotMotion.setAngles("LElbowYaw", anglesElbowYaw, 0.3f); // this is where the elbow starts rotating
        robotMotion.setAngles("LElbowRoll", anglesElbowRoll, 0.3f); // this is where the elbow starts turning
        this.nao.openHand("LHand"); // this is to open the hand to make sure you can give the robot a high five and not a fist bump
        Thread.sleep(4500); // this is a time period where the person on the receiving end has the time to give the high five
        this.nao.closeHand("LHand"); // this is to close the hand
        anglesShoulderPitch = Math.toRadians(65); // this is where the angles get set back
        anglesShoulderRoll = Math.toRadians(18);
        anglesElbowYaw = Math.toRadians(-80);
        anglesElbowRoll = Math.toRadians(0);
        robotMotion.setAngles("LShoulderPitch", anglesShoulderPitch, 0.1f); // this is where the shoulder gets set back downwards
        robotMotion.setAngles("LShoulderRoll", anglesShoulderRoll, 0.1f); // this is were the shoulder gets back closer to the body
        robotMotion.setAngles("LElbowYaw", anglesElbowYaw, 0.1f); // this is where the elbow starts rotating back
        robotMotion.setAngles("LElbowRoll", anglesElbowRoll, 0.1f); // this is where the elbow starts turning back
        Thread.sleep(500);
        nao.setLanguage("Dutch"); // this is to change the language back into Dutch
        robotMotion.setStiffnesses("LArm", 1.0); // this is where the arm gets put back in proper place
    }
}
