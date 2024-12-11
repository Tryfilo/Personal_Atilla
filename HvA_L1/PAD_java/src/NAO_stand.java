public class NAO_stand {

    private NAO nao;

    public NAO_stand(NAO nao) {
        this.nao = nao;
    }

    // this method is used to let the NAO stand
    public void stand() throws Exception {
        System.out.println("Is going to stand");
        nao.speak("Ik  ga  staan");
        nao.postureSetUp("Stand");
    }
}
