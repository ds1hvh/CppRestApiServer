var app = new Vue({
    el: "#app",
    data() {
        return {
            size : 2,
            result: ""
        }
    },
    methods: {
        postButton: function () {
            const baseURI = 'http://localhost:8080';
            this.$http.post(`${baseURI}/posts`, { size:this.size })
                .then((result) => {
                    console.log(result)
                    this.result = result.data
                })
        }
    }
})