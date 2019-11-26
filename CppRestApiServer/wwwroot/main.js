var app = new Vue({
    el: "#app",
    data() {
        return {
            size : 2,
            result: ""
        }
    },
    methods: {
        postButton() {
            const baseURI = 'http://localhost:8080';
            console.log("!!");
            axios.post(baseURI+'/game', { "size":this.size })
                .then((result) => {
                    console.log(result)
                    this.result = result.data
                }).catch((error) => {
                    console.log(error)
                })
        }
    }
})