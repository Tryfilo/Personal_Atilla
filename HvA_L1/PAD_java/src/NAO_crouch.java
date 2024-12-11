public class NAO_crouch {

    private NAO nao;

    public NAO_crouch(NAO nao) {
        this.nao = nao;
    }

    // this method is used to let the robot crouch
    public void crouch() throws Exception {
        System.out.println("Is going to crouch");
        nao.speak("Ik  ga  hurken");
        nao.postureSetUp("Crouch");
    }
}
